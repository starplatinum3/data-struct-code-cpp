

#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
const int N=222;
//vector<int>g[N];
int g[N][N];
int vis[N];
int check(vector<int> arr) {
	fill(vis,vis+N,0);
//	因为没有fill 
	for(int i=0; i<arr.size(); i++) {
		vis[arr[i]]=1;
		for(int j=0; j<arr.size(); j++) {
			if(i!=j&&!g[arr[i]][arr[j]]) {
				return -1;
//				not cli
			}
		}
	}


	for(int j=1; j<=n; j++) {
//		尝试一个点 连上 才去看其他点
//不然 看都不看 
		if(!vis[j]&&g[arr[0]][j]) {
			int conn=1;
			int i; 
			for( i=0; i<arr.size(); i++) {
				if(!g[j][arr[i]] ) {
					conn=0;
//					只要是有一个点 不连上 那就是不行 
					break;
				}
			}
			if(i==arr.size())return 0;
//			if(conn) {
//				return 0;
////				not max
//			}
		}
	}

	return 1;
//	for(int i=0; i<arr.size(); i++) {
//		for(int j=1; j<=n; j++) {
//			if(!vis[j]&&g[arr[0]][j]) {
//
//			}
//		}
//	}

}

//a 
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
//		g[u].push_back(v);
//		g[v].push_back(u);
		g[u][v]=g[v][u]=1;
	}
	scanf("%d",&k);
	for(int i=0; i<k; i++) {
		int cnt;
		scanf("%d",&cnt);
		vector<int>arr;
		for(int j=0; j<cnt; j++) {
			int x;
			scanf("%d",&x);
			arr.push_back(x);
		}
		int ch=check(arr);
		if(ch==-1) {
			printf("Not a Clique\n");
		} else if(ch==0) {
			printf("Not Maximal\n");
		} else {
			printf("Yes\n");
		}
	}
}
