#include<bits/stdc++.h>
int cntCity,cntWay,cntCheck;

// 该题需要修的道路数是连通集的个数-1

// 连通块个数
// ————————————————
// 版权声明：本文为CSDN博主「扯淡_yl」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/qq_36589706/article/details/87916890


int main(){
    scanf("%d%d%d", &cntCity, &cntWay, &cntCheck);
    for(int i=0;i<cntWay;i++){
        
    }
}


#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1010;
const int INF=1000000000;
int N, M, K;
int d[maxn][maxn], visit[maxn];
vector<int>G[maxn];
int query;
void dfs(int index){
	if(index==query)return;
//     这个点 是要去掉的
	visit[index]=1;
	for(int i=0; i<G[index].size(); i++){
		int v=G[index][i];
		if(visit[v]==0){
			dfs(v);
		}
	}
}
int main(){
	int a, b;
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<M; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0; i<K; i++){
		int cnt=0;
		scanf("%d",  &query);
		memset(visit, 0, sizeof(visit));
		for(int j=1; j<=N; j++){
//             query 点排除， 每次有一个没有vis 的 就cnt++
//              因为 如果联通的话 有些点就 vis 了
//             没有vis 就是一个新的不联通的块了
// 1 2 
// 1 3
// 如果1 沦陷了 2 3 就需要桥梁了
			if(visit[j]==0&&j!=query){
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n", cnt-1);
	}
	return 0;
}
