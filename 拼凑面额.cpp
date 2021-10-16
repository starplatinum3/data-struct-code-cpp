#include<stdio.h>

int w[]={1,5,10,20,50,100};
long long dp[10][10005];
// https://blog.csdn.net/weixin_43772166/article/details/89853597
int main(void)
{
	int W;
	scanf("%d",&W);
	dp[0][0]=1;
	for(int i=0;i<6;i++)
		for(int j=0;j<=W;j++)
		{
            // 获得的东西 少的话,还不如不要
			if(j<w[i])
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=dp[i][j]+dp[i+1][j-w[i]];
                // 举例她的 价值,如果j价值比w[i]大的话,
                // 前i个 组成j价值, 前i+1 个组成 j-w[i] 价值
		}
	printf("%lld\n",dp[6][W]);
	return 0;
}
