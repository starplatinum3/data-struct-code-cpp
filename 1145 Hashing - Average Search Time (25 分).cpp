
#include <bits/stdc++.h>
using namespace std;
int n,m,siz;
int tsiz;
vector<int>v;
int isp(int x) {
	int sq=sqrt(x);
	for(int i=2; i<=sq; i++) {
		if(x%i==0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	scanf("%d%d%d",&siz,&n,&m);

	for(tsiz=siz; !isp(tsiz); tsiz++);
		v.resize(tsiz);
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d",&x);
		int ha=0;
		for(int j=0; j<tsiz; j++) {
			int pos=(j*j+x)%tsiz;
			if(v[pos]==0) {
				v[pos]=x;
				ha=1;
				break;
			}
		}
		if(!ha) {
			printf("%d cannot be inserted.\n",x);
		}

	}
	int cnt=0;
	for(int i=0; i<m; i++) {
		int x;
		scanf("%d",&x);
		int ha=0;
		for(int j=0; j<=tsiz; j++) {
			int pos=(j*j+x)%tsiz;
			cnt++;
			if(v[pos]==0||v[pos]==x) {
				ha=1;
				break;
			}
		}
	}
	printf("%.1f\n",cnt*1.0/m);
//	printf("cannot be inserted.\n");
}
