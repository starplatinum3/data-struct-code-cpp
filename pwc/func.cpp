
#include<stdio.h>
#include<string.h>
// int fun(int arr[]);
int fun(int arr[2]);

// int fun(int arr[]){
//     printf("%d",1);
// }

int fun(int arr[2]){
    printf("%d",1);
}



// https://blog.csdn.net/mayue_web/article/details/86551952
int main(){
    // int intArr=new int[3];
    // int intArr[3]=new int[3];
    //  int intArr[3]={1,2,3};
    // fun(intArr);
    // 没有报错 所以这个长度没关系
    // 1

    int strLen= strlen("A\0B\0C");
    printf(" strLen %d",strLen);
    //  strLen 1
    return 0;
}