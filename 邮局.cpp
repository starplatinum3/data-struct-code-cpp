#include <bits/stdc++.h>
using namespace std;
 
const double inf = 1.7e300;
 
struct node
{
	int x, y;
}point[100], post[100];
 
double mp[101][101];
int flag[100];
int n, m, k;
double res = inf;
int cur[100];
int ans[100];
 
 
double dis(node a, node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
//  包含k个整数 要选的 邮局
// sum_k 现在选的个数吗？
// 1.sum_r表示最小距离和
void dfs(int st, int sum_k, double sum_r, double tmp_r[])
{
	if((k - (sum_k-1)) > (m - (st-1))) {
        return ;//剪枝 1
    }
	if(st > m && sum_k <= k) return ; //剪枝 2
	if(sum_k > k+1) return ;
	//cout << st-1 << " " <<  sum_k-1 << " " << sum_r << endl;
	if(sum_k == k+1)
	{
		//cout <<" shuchu" << st-1 << " " << sum_k-1 << " " << sum_r << endl;
		if(res > sum_r)
		{
			res = sum_r;
			for(int i = 1; i <= k; i++)
			{
				ans[i] = cur[i];
			}
			//cout << "   " << res << endl;
		}
		return ;
	}
    double dis_r[55];
    for(int i = 1; i <= n; i++)
    {
        dis_r[i] = tmp_r[i];//必须重新定义一个数组才属于这个函数
    }
 
	dfs(st+1, sum_k, sum_r, dis_r);//不建造此邮局
 
    if(flag[st] == 1) return ;
	cur[sum_k] = st;
	int mark1 = 0, mark2 = 0;
	if(sum_k == 1)//第一个邮局，初始化 dis_r
	{
		for(int i = 1; i <= n; i++)
		{
			dis_r[i] = mp[i][st];
			sum_r += mp[i][st];
		 }
		 mark1 = 1;
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(dis_r[i] > mp[i][st])
			{
				mark2 = 1;
				sum_r += mp[i][st] - dis_r[i];
				dis_r[i] = mp[i][st];
			}
		 }
	}
    if(mark1==0&&mark2==0) flag[st] = 1;
	if(mark1 == 1 || mark2 == 1) dfs(st+1, sum_k+1, sum_r, dis_r);
	return ;
}
 
void init()
{
    for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &point[i].x, &point[i].y);
	}
 
	for(int i = 1; i <= m; i++)
	{
		scanf("%d %d", &post[i].x, &post[i].y);
	}
 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			mp[i][j] = dis(point[i], post[j]);
		}
	}
}

// https://blog.csdn.net/yinghui_yht/article/details/79721425
 
int main()
{
	scanf("%d %d %d", &n, &m, &k);
    init();
	double dis_r[55];
    // 数组每个村民到邮局的最小距离
	memset(dis_r, -1, sizeof(dis_r));
	dfs(1, 1, 0, dis_r);
	for(int i = 1; i <= k; i++)
	{
		cout << ans[i] << " " ;
	}
	
	return 0;
 }