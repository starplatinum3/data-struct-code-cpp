//
// Created by Lenovo on 2020/12/10.
//

#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include<math.h>
void radixsort(int *a,int N,int num)
{
    int basenum = 1;
    for(int i = 0 ; i < num ; i++)
    {
        int past[10000];
        int number[10] = {0};
        for(int i = 0 ; i  < N ; i ++)
        {
//            111 /1 ==111 ... 111%10=1 ,取得最后一位
////123 /1 =123  123%10=3
////  111 /10 ==11 11%10=1
////          123/10=12 12%10=2 ,取得倒数第二位
            number[((a[i]/basenum)%10)] ++;
        }
//   0  1 ， 1  2 ，2 3，  3 4 ，累加
        for(int i = 1 ; i < N ; i++)
            number[i] += number[i-1];
//        number [1] 是 number[0]+ number[1]
//就是 1为最后一位和0为最后一位的加起来
        for(int i = N-1 ; i>=0 ; i-- )
        {
//            现在为基准的那位数 现在有几个然后去算他放在past里的下边
//比如说 现在以倒数第二个为基准 有 133 134 这个3 的
// number[3] == number[1.2.3]累加的 为什么 因为这是下标 3 要给前面的1 2 腾出位置，所以
//先算出了累加的 3 的最后的位置，然后3的拿出一个 他的number 就--， 这样就放3的倒数第二个了
             past[  number[((a[i]/basenum)%10)] - 1] = a[i] ;
            number[((a[i]/basenum)%10)] --;
//            这种最小位的数变少了一个
        }
//        每一轮
        for(int i = 0 ; i < N ; i++)
        {
            printf("%d ",past[i]);
        }
        printf("\n");
        for(int i = 0 ; i < N ; i ++)
            a[i] = past[i];
        basenum *=10;
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int *a = new int[N];
    int max = 0 ;
    for(int i = 0 ; i < N ; i ++)
    {
        scanf("%d",&a[i]);
        if(a[i] > max )
            max = a[i];
    }
    int num  = 0;
    while(max != 0)
    {
        max = max / 10;
        num ++;
    }
//    最大数字有几位数 num
    radixsort(a,N,num);
}

//https://blog.csdn.net/weixin_46047462/article/details/109981071

int main(){
    printf("930 63 83 184 505 278 8 109 589 269 \n"
           "505 8 109 930 63 269 278 83 184 589 \n"
           "8 63 83 109 184 269 278 505 589 930 ");
}