#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
 
int n,m;
int a[100010],b[100010],c[100010];
//  数值      前缀和    取余后和为i的个数；
int main()
{
    // https://blog.csdn.net/titi2018815/article/details/90287759
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        long long int sum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=(b[i-1]+a[i])%m;//前缀和，记得取余，否则数值太大；
            sum+=c[b[i]];//两个数值相等时必定有一个区是K的倍数；
            // 个数
            c[b[i]]++;//个数记得加一；
        }
        printf("%lld\n",sum+c[0]);//记得加上自己可以构成一个区间的情况；
    }
    return 0;
}