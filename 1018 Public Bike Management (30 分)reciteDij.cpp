#include<bits/stdc++.h>
using namespace std;

int cMax,n,sp,m;
const int N=555;
int c[N];
typedef vector<int> Path;
int dis[N],vis[N];
//vector<Path> pas;
Path pas[N];
//程序半路崩坏了 因为 定义了
// /vector<Path> 但是没有 resise
Path pa;
const int INF=0x3f3f3f3f;
vector<int>g[N];
int len[N][N];
int visPa[N];
Path tmp;
int maBik=-INF;
Path ansPa;
int miNeed=INF;
int ansBack=0;
void dfs(int u,int bik) {
	if(u==0) {
//		if(maBik<bik) {
//			maBik=bik;
//			ansPa=tmp;
//		}
		int back=0,need=0;
		for(int i=tmp.size()-1; i>=0; i--) {
			int id=tmp[i];
			if(c[id]>0) {
				back+=c[id];
			} else {
				if(back<(0-c[id])) {
//					不够 放
					need+=(0-c[id])-back;
					back=0;
				} else {
					back+=c[id];
				}
			}
		}

		if(miNeed>need) {
			ansBack=back;
			miNeed=need;
			ansPa=tmp;
		}
		
		if(miNeed==need&&ansBack>back) {
			ansBack=back;
			miNeed=need;
			ansPa=tmp;
		}

		return;
	}
	for(int v:pas[u]) {
		if(visPa[v])continue;
		visPa[v]=1;
		tmp.push_back(v);
		dfs(v,bik+c[v]);
		tmp.pop_back();
		visPa[v]=0;
	}
}

//ac
void dij() {
	fill(dis,dis+N,INF);
	dis[0]=0;
	while(1) {
		int u=-1;
		int mi=INF;
		for(int j=0; j<=n; j++) {
			if(vis[j])continue;
//			printf("dis[j] %d\n",dis[j]) ;
			if(dis[j]<mi) {
				mi=dis[j];
				u=j;
			}
		}
//		printf("mi %d\n",mi);
//		printf("u %d\n",u);
		if(u==-1)break;
		vis[u]=1;
		for(int v:g[u]) {
//			printf("v %d\n",v);
			if(vis[v])continue;
			if(dis[v]>dis[u]+len[u][v]) {
				dis[v]=dis[u]+len[u][v];
				pas[v].clear();
				pas[v].push_back(u);
//				printf("v %d u %d\n",v,u);
			} else if(dis[v]==dis[u]+len[u][v]) {
				pas[v].push_back(u);
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d",&cMax,&n,&sp,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",c+i);
		c[i]-=cMax/2;
	}
	for(int i=0; i<m; i++) {
		int u,v,le;
		scanf("%d%d%d",&u,&v,&le);
		g[u].push_back(v);
		g[v].push_back(u);
		len[u][v]=len[v][u]=le;

	}

	dij();
//	printf("%d",dis[sp]);
	tmp.push_back(sp);
	visPa[sp]=1;
	dfs(sp,c[sp]);

	printf("%d ",miNeed);
	int fir=1;
	for(int i=ansPa.size()-1; i>=0; i--) {
		if(fir) {
			fir=0;
		} else {
			printf("->");
		}
		printf("%d",ansPa[i]);
	}
	printf(" %d",ansBack);

}
