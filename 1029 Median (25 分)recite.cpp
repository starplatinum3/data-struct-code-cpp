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

//k ���ƽ� a ����  
		for(;a[k]<val;k++){
			cnt++;
//			��Ϊ cnt ��++ �� ����, ��1 ��ʼ ������ (m+n+1)/2;
//������ (m+n-1)/2; 
			if(cnt==mid){
				cout<<a[k];
			  
			}
		}
//		a �ﲻ�� �ٿ���b , bֻ�Ƕ�����һ�� ����ֻҪһ��
//˭�ȵ��� mid �ĸ��� ����˭  ��Ϊ�Ѿ������� 
		cnt++;
		if(cnt==mid){
				cout<<val;
				 
			}
	}
//	b �ﶼ���� ֻ����a ����� 
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
