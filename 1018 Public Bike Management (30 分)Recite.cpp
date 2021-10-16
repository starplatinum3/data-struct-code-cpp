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
using namespace std;
//1014-Waiting in Line (30 ��)ģ��ʱ�������
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
	for(int i=1; i<=numSta; i++) {
		if(vis[i]==false&&dis[i]<minDis) {
			minDis=dis[i];
			v=i;
		}
	}
	return v;
}
vector<int>pre[MAX_STA_CNT];
void reduce(int v) {
	//         ������չ
	for(int u=1; u<=numSta; u++) {
		if(vis[u])continue;

		if(dis[u]>dis[v]+g[v][u]) {
			dis[u]=dis[v]+g[v][u];
			pre[u].clear();
//             ���̵�· ֮ǰ��· ȡ�� ������
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
	for(int i=1; i<=numSta; i++) {
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
//             ������� �ӻص�back �� ��������
//Ϊʲôһ��Ҫ������, �����Ļ����ǻ�Ҫ�ٴ����� 
//��Ȼ֮���������Ҫ�� ��Ҫ�������õ������г�������
//��������������ڵ�һ����, �ǲ���û��Ҫ���� 
			if(num[id]>0) {
//                 back enough
				back+=num[id];
//				 And more, all the stations on the way will be adjusted as well.
//			Ҳ����˵һ��Ҫ������ 
			} else {
//				��Ҫ 3����, ���������2
//��ô��Ҫ����ȥ1 ����+= �� ,��Ϊ+= һ������ 
				if(back<(0-num[id])) {
//                 ���� Ҫ�ŵ㶫����ȥ
//�������Ĳ����ŵ����� 
					back+=num[id];
				} else {
//					��������ȫ������ Ҳ������ 
//modomodo �������!! 
					need+=(0-num[id])-back;
					back=0;
//					�������� ʲôҲ������ȥ 
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
	for(int i=1; i<numSta; i++) {
		dis[i]=INF;
	}
	for(int i=0; i<numSta; i++) {
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
	for(int i=0; i<roaCnt; i++) {
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
	printf("%d\n",minBack);
	return 0;
}


