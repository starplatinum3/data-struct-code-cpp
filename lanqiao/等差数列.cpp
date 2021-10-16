#include<bits/stdc++.h>
using namespace std;
int a[100005];
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
	
} 

// https://blog.csdn.net/sueong/article/details/109122993
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; 
	}
	sort(a,a+n);
	int d=a[1]-a[0];
	// if(d==0) {
	// 	cout<<d;
	// 	// cout<<0;
	// 	return 0;
		 
	// } 
	for(int i=2;i<n;i++){
		d=gcd(d,a[i]-a[i-1]);
		// cout<<d<<endl;
	} 
	cout<<(a[n-1]-a[0])/d+1;
	return 0;
}
