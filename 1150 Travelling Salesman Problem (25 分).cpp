#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
const int N=222;
int len[N][N];
int g[N][N];
int sum=0;
const int INF=0x3f3f3f3f;
int mi=INF,mik;
//,int eve
int vis[N];
int che(int k) {
	

	
	vector<int>a;
	int cnt;
	scanf("%d",&cnt);
	fill(vis,vis+N,0);
	for(int j=0; j<cnt; j++) {
		int x;
		scanf("%d",&x);
		a.push_back(x);
		vis[x]=1;
	}
	
		int eve=1;
	for(int i=1;i<=n;i++) {
		if(vis[i]==0) {
			eve=0;
		}
	}
	
	
	sum=0;
	int road=1;
	for(int i=0; i<a.size()-1; i++) {
		if(len[a[i]][a[i+1]]==0) {
//			return -1;
			road=-1;
//			没有通路
		}
		sum+=len[a[i]][a[i+1]];
	}

//printf("a[0] a.back() %d %d\n",a[0],a.back());
//printf("eve %d\n",eve);
	if(a[0]!=a.back()||eve==0) {
		return -2;
//	not
	}
//	有通路 但是不是simp
	if(cnt!=n+1) {
		road=0;
//		不是最小的
	}
	if(road==0||road==1) {
		if(mi>sum) {
			mi=sum;
			mik=k;
		}
	}

	return road;

}

//a
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		int u,v,le;
		scanf("%d%d%d",&u,&v,&le);
		len[u][v]=len[v][u]=le;
		vis[u]=vis[v]=1;
	}
	scanf("%d",&k);
//	int eve=1;
//	for(int i=1; i<=n; i++) {
//		if(vis[i]==0) {
//			eve=0;
//		}
//	}
	for(int i=1; i<=k; i++) {
//		,eve
		int ch=che(i);

		if(ch==-1) {
			printf("Path %d: NA (Not a TS cycle)\n",i);
		} else if(ch==0) {
			printf("Path %d: %d (TS cycle)\n",i,sum);
		} else if(ch==1) {
			printf("Path %d: %d (TS simple cycle)\n",i,sum);
		} else if(ch==-2) {
			printf("Path %d: %d (Not a TS cycle)\n",i,sum);
		}
	}
	printf("Shortest Dist(%d) = %d\n",mik,mi);
}
