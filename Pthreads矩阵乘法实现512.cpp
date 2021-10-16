#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <sys/time.h>
//  https://blog.csdn.net/lcx543576178/article/details/84719881
int thread_count;
int size, local_size;
int *a, *b, *c;
FILE *fp;
 
int* transpose_matrix(int *m, int size);
 
void* Init();
 
void* pthread_mult(void* rank);
 
int main(int argc, char* argv[]){
    int i, j;
    long thread;
 
    float time_use = 0;
    struct timeval start;
    struct timeval end;
 
    size = 512;
 
    gettimeofday(&start, NULL);
 
    pthread_t* thread_handles;
//  10进制
thread_count=4;
    // thread_count = strtol(argv[1], NULL, 10);
//  1000 /4 ==250 
    local_size = size/thread_count;
 
    thread_handles = malloc(thread_count * sizeof(pthread_t));
 
    Init();
 
    for(thread = 0; thread<thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, pthread_mult, (void*) thread);
 
    for (thread=0; thread<thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);
 
    fp=fopen("c.txt","w");//打开文件
    for(i=0;i<size;i++) {//写数据
        for(j=0;j<size;j++)
            fprintf(fp,"%d ",c[i*size+j]); 
        fputc('\n',fp); 
    }
    fclose(fp);//关闭文件
 
    gettimeofday(&end, NULL);
    time_use = (end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);
 
    printf("time_use is %f\n", time_use/1000000);
 
    free(thread_handles);
    free(a);
    free(b);
    free(c);
    return 0;
}
//  转置
int* transpose_matrix(int *m, int size){
    int i, j;
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            int temp = m[i*size+j];
            m[i*size+j] = m[j*size+i];
            m[j*size+i] = temp;
        }
    }
    return m;
}
 
void* Init(){
 
    int i, j;
 
    a = (int*)malloc(sizeof(int)*size*size);
    b = (int*)malloc(sizeof(int)*size*size);
    c = (int*)malloc(sizeof(int)*size*size);
 
    //从文件中读入矩阵
    fp=fopen("mat_a.txt","r");//打开文件
    for(i=0;i<size;i++) //读数据
        for(j=0;j<size;j++)
            fscanf(fp,"%d",&a[i*size+j]);
    fclose(fp);//关闭文件
 
    fp=fopen("mat_b.txt","r");
 
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            fscanf(fp,"%d",&b[i*size+j]);
    fclose(fp);
 
    b = transpose_matrix(b, size);
}
 
void* pthread_mult(void* rank){
    long my_rank = (long) rank;
    int i, j, k, temp;
    // 0 *250
    // 1*250-1 
    // ..
    // 1*250 
    // 2*250-1 ...
    int my_first_row = my_rank*local_size;
    int my_last_row = (my_rank+1)*local_size - 1;
//  每个线程 一部分的row
    for(i = my_first_row; i <= my_last_row; i++){
        for(j = 0; j<size; j++){
            temp = 0;
            for(k = 0; k<size; k++)
                temp += a[i*size+k] * b[j*size+k];
            c[i*size+j] = temp;
        }
 
    }
}
