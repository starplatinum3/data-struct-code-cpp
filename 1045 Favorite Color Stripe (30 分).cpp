#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int vis[205];
int col[205];
int dd[maxn], dp[maxn];
//https://blog.csdn.net/galesaur_wcy/article/details/84789292
//a
//1045 Favorite Color Stripe ��30 �֣�������������б��Σ�
int main() {
	int k ;
	scanf("%d", &k);
	int n, m ;
	scanf("%d", &n);
	int gg = 0;
	for(int i = 1; i <= n ; i ++) {
		scanf("%d",&col[i]);
		vis[col[i]] = ++gg;
	}
	scanf("%d",&m);
	int x,now = 0;
	for(int i = 1; i <= m ; i ++) {
		scanf("%d", &x);
//		printf("x %d \n",x);
//		ǰ����ֹ�  ����4 ��û�г���
		if(vis[x] >= 1) {
//			printf("vis[x] >= 1\n");
//			printf(" x  vis[x] %d %d\n",x,vis[x]);
			++now;
//			printf("now %d\n",now);
			dd[now] = vis[x];
//				dd ���� ���ֵ��±�
		}

	}
	//���������Ӧ��������������� ���������ظ���
//	���ض���ɫ���а�������ţ�ͬʱ�ų�����ϲ������ɫ
	int maxn = 0;
	for(int i = 1; i <= now; i ++) {
		dp[i] = 1;
//		���ڲ���д
		for(int j = 1; j < i; j ++)
//		for(int j = 1; j <= i; j ++)
		{
//			dd ���� 1 ��ʼ������
			if(dd[i] >= dd[j])
				dp[i] = max(dp[i],dp[j] + 1);
		}
		maxn = max(maxn,dp[i]);
//		printf("dp[%d] = %d\n",i,dp[i]);
	}
	printf("%d\n",maxn);
	return 0;
}
