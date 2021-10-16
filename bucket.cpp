//
// Created by Lenovo on 2020/12/17.
//
#include <bits/stdc++.h>
const  int N=1e3+7;
int a[N];
int bucket(int len)
{
    int book[1001],i,j,t,n;
    for(i=0;i<=1000;i++)
        book[i]=0;
    //scanf("%d",&n);//输入一个数n，表示接下来有n个数
    for(i=0;i<len;i++)//循环读入n个数，并进行桶排序
    {
        //  scanf("%d",&t);  //把每一个数读到变量t中
        book[a[i]]++;  //进行计数，对编号为t的桶放一个小旗子
    }
    for(i=1000;i>=0;i--)  //依次判断编号1000~0的桶
        for(j=1;j<=book[i];j++)  //出现了几次就将桶的编号打印几次
            printf("%d ",i);
    //   getchar();getchar();
    return 0;
}

int mainBucket(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    bucket(n);


}