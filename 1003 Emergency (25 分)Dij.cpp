#include<bits/stdc++.h>
using namespace std;

int n,m,st,en;
const int N=555;
int re[N];
int len[N][N];
vector<int>g[N];
int dis[N];
const int INF=0x3f3f3f3f;
int vis[N],res[N];
int paCnt=1;
int roCnt[N];
void dij() {
	fill(dis,dis+N,INF);
	dis[st]=0;
	res[st]=re[st];
	roCnt[st]=1;
//	一开是 是re个
	while(1) {
		int u=-1;
		int mi=INF;

		for(int j=0; j<n; j++) {
			if(vis[j])continue;
			if(mi>dis[j]) {
				mi=dis[j];
				u=j;
			}
		}
		if(u==-1) {
			break;
		}
		vis[u]=1;
		for(int v:g[u]) {
			if(vis[v])continue;
			if(dis[v]>dis[u]+len[u][v]) {
				dis[v]=dis[u]+len[u][v];
				res[v]=res[u]+re[v];
				roCnt[v]=roCnt[u];
//				paCnt=1;
//				printf("more short path cnt %d\n",paCnt);
//				printf("v: %d u %d\n",v,u);
			} else if(dis[v]==dis[u]+len[u][v]) {

				if(res[v]<res[u]+re[v]) {
					res[v]=res[u]+re[v];
				}
//			          	printf("v %d u %d\n",v,u);

//				paCnt++;
				roCnt[v]+=roCnt[u];
//				printf("more path cnt %d\n",paCnt);
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d",&n,&m,&st,&en);
	for(int i=0; i<n; i++) {
		scanf("%d",re+i);
	}
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			len[i][j]=INF;
		}
	}
	for(int i=0; i<m; i++) {
		int u,v,leng;
		scanf("%d%d%d",&u,&v,&leng);
		len[u][v]=len[v][u]=leng;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dij();
	printf("%d %d\n",roCnt[en],res[en]);
//	printf("dis[en] %d\n",dis[en]);
}
