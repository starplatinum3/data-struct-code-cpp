#include<bits/stdc++.h>
using namespace std;

//a
int n,m;
const int N=555;
vector<int>g[N];
int vis[N];
void dfs(int u){
	vis[u]=1;
	for(int v:g[u]){
		if(vis[v])continue;
		dfs(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	int ye=1;
	int cnt=0;
	int fir=1;
	for(int i=1;i<=n;i++){
		if(fir)fir=0;
		else printf(" ");
		printf("%d",g[i].size());
		if(g[i].size()%2==1){
			cnt++;
		}
		if(!vis[i]){
			ye=0;
		}
	}
	
	printf("\n");
	if(ye==0||cnt>2){
		printf("Non-Eulerian");
	}else if(cnt==2){
		printf("Semi-Eulerian");
	}else if(cnt==0){
			printf("Eulerian");
	}
	
} 
