#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define INF 0x3f3f3f3f
//a
using namespace std;
//1014-Waiting in Line (30 分)模拟时间的做法
typedef long long ll;
const int MAX_STA_CNT=505;
int capMax,numSta,idxSta,roaCnt;
//  int n,m,k,q;
int num[MAX_STA_CNT];
// const int INF=0x3f3f3f3f;
int  g[MAX_STA_CNT][MAX_STA_CNT];
int dis[MAX_STA_CNT];
bool vis[MAX_STA_CNT];
int getMinDisPo() {
	int v=-1;
	int minDis=INF;
//      (the stations are numbered from 1 to N, and
// 	int i=1;
//     0 是包括一开始点的意思嘛
    for(int i=0; i<=numSta; i++) {
		if(vis[i]==false&&dis[i]<minDis) {
			minDis=dis[i];
			v=i;
		}
	}
	return v;
}
vector<int>pre[MAX_STA_CNT];
void reduce(int v) {
	//         往外扩展
//     int u=1; 

	for(int u=0; u<=numSta; u++) {
		if(vis[u])continue;
if(g[v][u]==INF)continue;
		if(dis[u]>dis[v]+g[v][u]) {
			dis[u]=dis[v]+g[v][u];
			pre[u].clear();
//             更短的路 之前的路 取消 不是了
			pre[u].emplace_back(v);
		} else if(dis[u]==dis[v]+g[v][u]) {
			pre[u].emplace_back(v);
		}
	}
}
void dij() {
//     for(int i=1;i<=numSta;i++){
//         dis[i]=INF;
//     }
	dis[0]=0;
    //     为甚0
//     (int i=1; 
	for(int i=0; i<=numSta; i++) {
		int v=getMinDisPo();
		if(v==-1)break;
		vis[v]=true;
		reduce(v);
	}
}
vector<int>tmpPath;
vector<int>path;
int minBack=INF,minNeed=INF;
void dfs(int pos) {
	tmpPath.emplace_back(pos);
	if(pos==0) {
		int back=0,need=0;
		for(int i=tmpPath.size()-1; i>=0; i--) {
			int id=tmpPath[i];
//             多出来了 加回到back 上 让他带走
			if(num[id]>0) {
//                 back enough
				back+=num[id];
			} else {
				if(back>(0-num[id])) {
//                 不够 要放点东西上去
					back+=num[id];
				} else {
					need+=(0-num[id])-back;
					back=0;
				}
			}
		}

		if(minNeed>need) {
			minBack=back;
			minNeed=need;
			path=tmpPath;
		} else if(minNeed==need&&minBack>back) {
			minBack=back;

			path=tmpPath;
		}
		tmpPath.pop_back();
		return;
	}


	for(auto u:pre[pos]) {
		dfs(u);
	}
//      tmpPath.emplace_back(pos);
	tmpPath.pop_back();
}
struct Node {
	int id,w;

};
int main() {
	scanf("%d%d%d%d",&capMax,&numSta,&idxSta,&roaCnt);
    fill(g[0],g[0]+MAX_STA_CNT*MAX_STA_CNT,INF);
	for(int i=1; i<=numSta; i++) {
		dis[i]=INF;
	}
	for(int i=1; i<=numSta; i++) {
		scanf("%d",num+i);
		num[i]-=capMax/2;
//     num[i]=
	}
//     s N non-negative numbers C
//   (i=1,?,N) w
    
// 	for(int i=1; i<MAX_STA_CNT; i++) {
// 		for(int j=1; j<MAX_STA_CNT; j++) {
// 			g[i][j]=INF;
// 		}
// 	}
	for(int i=1; i<=roaCnt; i++) {
		int u,v,len;
		scanf("%d%d%d", &u,&v,&len);
		g[u][v]=len;
		g[v][u]=len;
	}
    dij();
	dfs(idxSta);
	printf("%d 0",minNeed);
	for(int i=path.size()-2; i>=0; i--) {
		printf("->%d",path[i]);
	}
	printf(" %d\n",minBack);
	return 0;
}


