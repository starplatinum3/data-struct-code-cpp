
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    int i;
    
    for(i=1;i<n;i+=2){
        printf("%d ",i);
        
    }
    printf("%d",i);
    
    return 0; 
}

#include<stdio.h>
int main()
{
    int x,js=0,os=0;
    do
    {
        scanf("%d",&x);
        if((x<=0&&x!=-1)||x>=100000)
            return 0;
        if(x%2==0)
        {
            os++;
        }
        else
        {
            js++;
        }
    }while(x!=-1);
    printf("%d %d",js-1,os);
    return 0;
}


#include<stdio.h>
int main()
{
    int x;
    int rate=1;
    int cnt=0;
    int mask=0;
    int real;
    scanf("%d",&x);
    int t=x;
    while(x>0){
        t=x%10;  //每次个位数
        
        x/=10;
        cnt++; //位数
        rate*=2;
        real=rate/2;
        if((cnt%2)==0){
            if((t%2)==0){
                mask+=real;
            }
        }else{
            if((t%2)!=0){
                mask+=real;
            }
        }
    }
    printf("%d",mask);
    return 0; 
 }
// ————————————————
// 版权声明：本文为CSDN博主「天山童老爷」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/weixin_44226341/article/details/108317278