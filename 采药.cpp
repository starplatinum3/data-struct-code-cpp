#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int v[105],w[105];
int dp[105][1005];
// https://blog.csdn.net/weixin_43772166/article/details/89853597
int main(void)
{
	int T,M;
	while(scanf("%d%d",&T,&M)!=EOF)
	{
		for(int i=0;i<M;i++)
			scanf("%d%d",&w[i],&v[i]);
		for(int j=0;j<=100;j++)
			dp[0][j]=0;
            // 山洞里没草药 自然是0
		for(int i=0;i<M;i++)
			for(int j=0;j<=T;j++)
			{
                // 列举时间
                // 采集这个草药的时间大于
                // 多采集一个草药 但是这个时间多 我就不采集了
                // 我总的时间都不够，想要分配也分配不出
				if(j<w[i])
					dp[i+1][j]=dp[i][j];
				else
					dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
                    // 如果这个时间花的有意义，我就尝试用掉这个时间 [j-w[i]
                    // 换取采集这个草药的价值
			}
            // 表示在规定的时间内，可以采到的草药的最大总价值。
            // T时间可以踩到价值
            // M代表山洞里的草药的数目
		printf("%d\n",dp[M][T]);
	}
	return 0;
}
