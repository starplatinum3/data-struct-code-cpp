#include<stdio.h>
#include<algorithm>
using namespace std;
// https://blog.csdn.net/weixin_43772166/article/details/89853597
int main(void)
{
	int k,ans,end;
	int arr[10005],dp[10005],first[10005];
	while(scanf("%d",&k)!=EOF&&k)
	{
		for(int i=0;i<k;i++)
			scanf("%d",&arr[i]);
		dp[0]=arr[0];
		ans=dp[0];end=0;
		first[0]=arr[0];
		for(int i=1;i<k;i++)
		{
			if(dp[i-1]<0)//这时需要把first设为当前数 
				first[i]=arr[i];
			else//否则和上一个相同 
				first[i]=first[i-1]; 
			dp[i]=max(arr[i],dp[i-1]+arr[i]);
			if(ans<dp[i])
				end=i;
			ans=max(ans,dp[i]);
		}
		printf("%d %d %d\n",ans,first[end],arr[end]);
	}
	return 0;
}
