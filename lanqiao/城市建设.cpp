#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
 
struct node
{
	int u,e,w;
}edge[900010];
 
int flag = 0;
int book[100100];
int pre[100100];
 
bool cmp(node a, node b)
{
	return a.w < b.w;
}
 
void init(int n)
{
	for(int i = 0; i <= n; i++)
	{
		pre[i] = i;
	}
}
 
int find(int x)
{
	if(pre[x] == x) return x;
	else return pre[x] = find(pre[x]);
}
 
int kruskal_first(int n, int m)//有码头参与 
{
	init(n);
	int sum = 0;
	flag = 0;
	for(int i = 0; i < m; i++)
	{
		if(edge[i].w == MAX) continue;
        // 不能 走
		int t1 = find(edge[i].u);
		int t2 = find(edge[i].e);
		if(t1!=t2 || edge[i].w < 0)
		{
			pre[t1] = t2;
			sum += edge[i].w; 
			
			if(edge[i].u == 0) flag++;
            //  码头
            // 一个码头是正常的
		}
	}
	return sum;
}
//  https://blog.csdn.net/yinghui_yht/article/details/79717818
int kruskal_second(int n, int m)
{
	init(n);
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		if(edge[i].u == 0) continue;
        // 不是码头
        // 不建造码头的话 会变少吗
		int t1 = find(edge[i].u);
		int t2 = find(edge[i].e);
		if(t1!=t2 || edge[i].w < 0)
		{
			pre[t1] = t2;
			sum += edge[i].w; 
		}
	}
    // 还有就是此题没必要找边长的个数，因为存在赚钱的边是一定要加入并查集的
// 也就是最小生成树不一定是 n-1 的边/
// 
	return sum;
}
 
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i < m; i++)
	{
		scanf("%d %d %d", &edge[i].u, &edge[i].e, &edge[i].w);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &book[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		edge[m].u = 0; edge[m].e = i;
        // 码头到 某个点的距离
		if(book[i] == -1) edge[m].w = MAX;
		else edge[m].w = book[i];
		m++;
	}
	
	sort(edge, edge+m, cmp);
	
	int ans1 = kruskal_first(n, m);
	//cout << flag << endl;
    // 一个码头的话 是没有意义的  所以要当作没有
	if(flag == 1)
	{
        // 还要再跑一个krus 来看看
		int ans2 = kruskal_second(n, m);
		printf("%d\n", ans2);
	}
	else
	{
		printf("%d\n", ans1);
	}
	//cout << ans1 << " " << ans2 << endl;
	
	
	return 0;
 } 