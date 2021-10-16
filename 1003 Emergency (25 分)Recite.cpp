//1003 Emergency (25 分)
#include<bits/stdc++.h>
using namespace std;
const int    MAX_N=507;
struct Node {
	int u,v,w;
};
int n,m;
int st,en;
int rescue[MAX_N];
// priority_queue<Node>q;
int resTot[MAX_N];
int totLen[MAX_N];
int tmpLen[MAX_N];
int len[MAX_N][MAX_N];
int INF=0x3f3f3f3f;
int vis[MAX_N];
int path[MAX_N];
int roCnt[MAX_N];
void dij() {
//     res[st]=0;
	memset(totLen,INF,sizeof totLen);
//	memset(tmpLen,0,MAX_N*sizeof totLen);
	memset(path,-1, sizeof path);
//     int u=st;
//	vis[st]=1;
	resTot[st]=rescue[st];
	roCnt[st]=1;
  totLen[st]=0;
//	printf("dij\n");
	for(;;) {
		int v=-1;
		for(int j=0; j<n; j++) {
			if(!vis[j]&&(v==-1||totLen[v]>totLen[j])) {
				v=j;
//                 break;
			}
		}
//         找出最短的
		if(v==-1)break;
//         i 是新找到的地方啊
		vis[v]=1;
		for(int i=0; i<n; i++) {
			if(vis[i])continue;

			if(totLen[i]>totLen[v]+len[v][i]) {
				roCnt[i]=roCnt[v];
				totLen[i]=totLen[v]+len[v][i];
				path[i]=v;
//                 resTot[v]
				resTot[i]=resTot[v]+rescue[i];
//                 原来的 加上路上新增的
			} else if(    totLen[i]==totLen[v]+len[v][i]) {
//                 v--> i
				roCnt[i]+=roCnt[v];
//                 人变多
				if(resTot[i]<resTot[v]+rescue[i]) {
					resTot[i]=resTot[v]+rescue[i];
					path[i]=v;
				}
			}
		}
	}

//     printPath();
	printf("%d %d\n",roCnt[en],resTot[en]);
//     for(;q.empty();)

//     }
}

void printPath() {
	int i=en;
	int fir=1;
	for(; path[i]!=-1; i=path[i]) {
		if(fir) {
			fir=0;
		} else {
			printf(" ");
		}
		printf("%d",path[i]);

	}
}
int main() {

//     int st,en;
	scanf("%d%d%d%d",&n,&m,&st,&en);
//	printf("%d\n",en);
	for(int i=0; i<n; i++) {
		scanf("%d",rescue+i);
	}
//	printf("rescu\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j)len[i][j]=0;
			else len[i][j]=INF;
		}
	}

	for(int i=0; i<m; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		len[u][v]=w;
		len[v][u]=w;
	}
//printf("dij before\n");
	dij();

}
