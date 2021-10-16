//1098 Insertion or Heap Sort (25 ·Ö)

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a,b;

void printV(vector<int>v) {
	int fir=1;
	for(int val:v) {
		if(fir)fir=0;
		else printf(" ");
		cout<<val;
	}
	printf("\n");
}
int main() {
	cin>>n;
	a.resize(n);
	b.resize(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++) {
		cin>>b[i];
	}
//	make_heap(b.begin(),b.end());
//	swap(b.begin(),b.end());
//printV(b);
//		swap(b[0],b[b.size()-1]);
	int i;
	for( i=n-1; b[i]>=b[0]; i--);
	swap(b[0],b[i]);
	printV(b);
//		make_heap(b.begin(),b.end());
//	make_heap(b.begin(),b.begin()+i);
//make_heap(b.begin()+i,b.end(),greater<int>());
//make_heap(b.begin(),b.begin()+i,greater<int>());
make_heap(b.begin(),b.end(),greater<int>());
	printV(b);

}
