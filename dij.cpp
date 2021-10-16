#include<bits/stdc++.h>
int vis[n];
void init() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			g[i][j]=INF;
		}
	}
}
int minDisPo() {
	int v=-1;
	int minDis=INF;
	for(int i=0; i<n; i++) {
		if(vis[i]==false&&dis[i]<minDis) {
			minDis=dis[i];
			v=i;
		}
	}
	return v;
//		if(v==-1)break;

}
void dij() {
	for(int i=0; i<n; i++) {
		dis[i]=g[s][i];
	}
	dis[0]=0;

	for(int i=1; i<=n; i++) {
		int v=minDisPo();
		if(v==-1)break;
		vis[v]=true;
		for(int u=0; u<n; u++) {
			if(vis[u]||len[v][u]==INF)continue;

			if(dis[u]>dis[v]+len[v][u]) {
				dis[u]=dis[v]+len[v][u];
			}
//			else if(dis[u]==dis[v]+len[v][u]) {
//             if()
//			}
		}
	}
}
