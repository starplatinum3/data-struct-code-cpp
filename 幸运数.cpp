//
// Created by Lenovo on 2021/2/24.
//

#include<bits/stdc++.h>
using namespace std;
int isLucky[1000000];//记录幸运数的位置，等于1则为幸运数
int deleted[1000000];//为1则表示已经删除，0则没有删除
int flag=0;//结束循环的标志
//
//    文档：历届试题 幸运数.note
//    链接：http://note.youdao.com/noteshare?id=d6d2d7ca7af0a0890abc76b93cf8e02f&sub=27594E80B0F54700ADC690DDED9FA5F0
//priority_queue

int main()
{
    int m,n;
    cin >> m >>  n;
    memset(deleted, 0, sizeof(deleted));
    memset(isLucky, 0, sizeof(isLucky));
    isLucky[1]=1;//
    int s=2;//当前幸运数。

    while(true){
        int a=0;
        for(int i=1;i<n;i++)
        {
            //为1则表示已经删除，0则没有删除
            if(deleted[i] == 0){
//                没删除的里面才要记数
                a++;
                //记录幸运数的位置，等于1则为幸运数
//                不是幸运数字
//a 最多也就==s 吧,应该不会变成s 的2倍吧
                printf("a: %d, now num : %d\n",a,i);
//前面几个是幸运数 ，后面的还不是
                if(a%s==0 && isLucky[i] != 1) {
                    deleted[i]=1;
//                    删除
                    a=0;
                }

            }
        }
        for(int i=1;i<n;i++){
            if(i==n-1) flag=1;
//            结束
            //记录幸运数的位置，等于1则为幸运数
//            不是幸运数 而且没有删除
            if(isLucky[i] == 0 && deleted[i] == 0)
            {
                s=i;
//                当前幸运数
//                变成幸运数
                isLucky[i]=1;
                break;
            }
        }

        if(flag==1) break;
    }
    int sum=0;
    for(int i=m+1;i<n;i++){
        //为1则表示已经删除，0则没有删除
        if(deleted[i] == 0)
            sum++;
    }
    cout << sum << endl;
    return 0;
}

//https://www.cnblogs.com/henuliulei/p/10460830.html