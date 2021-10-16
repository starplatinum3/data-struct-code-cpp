//1126 Eulerian Path (25 ·Ö)

#include<bits/stdc++.h>
using namespace std;
int n,m;

const int N=555;
vector<int>g[N];
int vis[N];
int cnt=0;
void dfs(int u){
	cnt++;
	for(int v:g[u]){
		if(vis[v])continue;
		vis[v]=1;
		dfs(v);
	}
}
int even=0;
// https://blog.csdn.net/qq_43738331/article/details/111408842
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vis[1]=1;
	dfs(1);
	int fir=1;
	for(int i=1;i<=n;i++){
		if(fir)fir=0;
		else printf(" ");
		printf("%d",g[i].size());
		if(g[i].size()%2==0){
			even++;
		}
	}
	printf("\n"); 
	// ?????? ????
	if(even==n&&cnt==n){
		printf("Eulerian");
	}else if(even==n-2&&cnt==n){
		printf("Semi-Eulerian");
	}else{
		printf("Non-Eulerian"); 
	}
	
} 
