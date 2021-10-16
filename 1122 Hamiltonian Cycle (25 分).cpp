//1122 Hamiltonian Cycle (25 ·Ö)
#include<bits/stdc++.h>
using namespace std;
const int N=222;
int g[N][N];
int n,m;
int k;
//https://blog.csdn.net/weixin_42240667/article/details/105324936
bool seeP(vector<int>v) {
    int vis[v.size()+1];
	bool fal=true;
	for(int i=0;i<=n;i++){
		vis[i]=0;
	}
	for(int i=0; i<v.size()-1; i++) {
		if(!g[v[i]][v[i+1]]) {
//			return false;
			fal=false;
		}
		vis[v[i]]++;
		
	}
	vis[v.back()]++;
	for(int i =1;i<=n;i++){
		if(vis[i]!=1&&i!=v.front()){
			fal=false;
		}
	}
	return fal;
//	return true;
}
int main() {
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		int u,v;
		cin>>u>>v;
		g[u][v]=g[v][u]=1;
	}
	cin>>k;
	for(int i=0; i<k; i++) {
		int cnt;
		scanf("%d",&cnt);
		vector<int>v;
		for(int j=0; j<cnt; j++) {
			int x;
			scanf("%d",&x);
			v.push_back(x);
		}
		if(v[0]!=v.back()) {
			printf("NO\n");
			continue;
		}
		if(v.size()!=n+1) {
			printf("NO\n");
			continue;
		}


//		for(int j=0;j<v.size()-1;j++){
//			if(!g[v[j]][v[j+1]]){
//				printf("NO\n");
//			}
//		}

		if(!seeP(v)) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
}
