#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
//const int maxn = 200010;
//int a[maxn];
vector<int>a;
 
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
//		cin >> a[i];
int val;
		cin>>val;
		a.emplace_back(val);
	}
 
	int m;
	cin >> m;
	int k=0,cnt=0;
	int mid=(m+n+1)/2;
	for (int i = 0; i < m; i++) {
        int val;
		cin >>val;
//		1 2 3 
//		 4 5 6

//k 先推进 a 数组  
		for(;a[k]<val;k++){
			cnt++;
//			因为 cnt 先++ 的 所以, 从1 开始 所以是 (m+n+1)/2;
//而不是 (m+n-1)/2; 
			if(cnt==mid){
				cout<<a[k];
			  
			}
		}
//		a 里不是 再看看b , b只是读入了一个 所以只要一次
//谁先到达 mid 的个数 就是谁  因为已经排序了 
		cnt++;
		if(cnt==mid){
				cout<<val;
				 
			}
	}
//	b 里都不是 只能是a 里的了 
		for(;k<n;k++){
			cnt++;
			if(cnt==mid){
				cout<<a[k];
			
			}
		}
		
//	sort(a, a + m + n);
//	cout << a[(m + n-1) / 2];
	return 0;
}
