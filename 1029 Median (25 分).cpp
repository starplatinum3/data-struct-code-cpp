
#include<bits/stdc++.h>
using namespace std;

vector<long long >v;
int main() {
	int siz;
	scanf("%d",&siz);
	for(int i=0; i<siz; i++) {
		long long val;
		scanf("%lld",&val);
		v.emplace_back(val);
	}

	scanf("%d",&siz);
	for(int i=0; i<siz; i++) {
		long long val;
		scanf("%lld",&val);
		v.emplace_back(val);
	}

	sort(v.begin(),v.end());
//     8/2 ==4
	int index=  (v.size()&1)?v.size()/2:(v.size()/2-1);
	cout<<v[index];
}
