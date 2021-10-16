
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1001;
vector<int>g[N];
//int in[N];
vector<int>in;
int k;
int notTop() {
	vector<int>tmpin=in;
	int no=0;
	for(int i=0; i<n; i++) {
		int x;
        // 一个拓扑序列 是不是
		scanf("%d",&x);
//		printf("tmpin[x] %d\n",tmpin[x]);
		if(tmpin[x]==0) {
			
			for(int v:g[x]){
				tmpin[v]--;
			}
		} else {
			no=1;
		}

	}
	return no;
}
vector<int>ans;
int main() {
	scanf("%d%d",&n,&m);
	in.resize(n+1);
	for(int i=0; i<m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		in[v]++;
	}
	scanf("%d",&k);
	for(int i=0; i<k; i++) {
		if(notTop()) {
			ans.push_back(i);
		}
	}

	int fir=1;
	for(int val:ans) {
		if(fir)fir=0;
		else printf(" ");
		printf("%d",val);
	}

}
