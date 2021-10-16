//1046 Shortest Distance (20 ·Ö)
#include<bits/stdc++.h>
using namespace std;
int n ,m ;
//a
const int N=100006;
int a[N];
long long  s[N];
long long sum(int l, int r) {
	return s[r]-s[l-1];
}

long long sumRev(int l, int r) {
	return sum(1,n)-sum(l,r);
}


int main() {
	scanf("%d",&n);

	for(int i=1; i<=n; i++) {
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	scanf("%d",&m);
	for(int i=0; i<m; i++) {
		int a,b;


		scanf("%d%d",&a,&b);
		if(a>b) {
			swap(a,b);
		}
		long long  sumZh=sum(a,b-1);
		long long  sumReverse=sumRev(a,b-1);
//		cout<<"sumZh  "<<sumZh<<"\n";
//			cout<<"sumReverse  "<<sumReverse<<"\n";
//		cout<<sum(a,b);
		cout<<min(sumZh,sumReverse)<<"\n";
	}
}
