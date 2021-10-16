 
#include<bits/stdc++.h>
// https://blog.csdn.net/u013852115/article/details/83384802
using namespace std;
#define ll long long
#define MAXN 100005
#define inf 0x3f3f3f3f3f3f3f3f
int n,m,cnt[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    // m 是他们相差的那个数字
    memset(cnt,0,sizeof cnt);
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        int d;
        scanf("%d",&d);
        // 每种数字有多少个
        cnt[d]++;
        maxx=max(maxx,d);
        // 数字里面最大的
    }
    int ans=0;
    //  m 是他们相差的那个数字
    for(int i=0;i+m<=maxx;i++)
    {
        // 两个数字相差最大 也只能是maxx 这么大
        // m！=0
        // 相差 可以配对的数字 都有的时候
        while(m && cnt[i]>0 && cnt[i+m]>0)
        {
            // 多匹配一个
            ans++;
            cnt[i]--;
            cnt[i+m]--;
        }
//        while(!m && cnt[i]>=2)
//        {
//            ans++;
//            cnt[i]-=2;
//        }
// m ==0
// 一样的数字
// 2 2 匹配了一组，  如果三个2 ，2 2 2 匹配了两组，也就是匹配了 cnt[i]-1;组
        if(!m && cnt[i]>=2)
        {
            ans+=cnt[i]-1;
            cnt[i]=1;
            // 为什么还要剩下一个呢，是不是末尾这一个还可以给别人匹配啊
        }
    }
    printf("%d\n",n-ans);
    return 0;
}