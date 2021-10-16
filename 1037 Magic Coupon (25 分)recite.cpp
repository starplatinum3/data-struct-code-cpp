//1037 Magic Coupon (25 ·Ö)
#include<bits/stdc++.h>
using namespace std;
vector<int>v1,v2;
int sum=0;
//a 
int main(){
		int n,m;
		int u=0,v=0,xx=0,yy=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d",&x);
		if(x>0){
			u++;
		}else if (x<0){
			v++;
		}
		v1.emplace_back(x);
	}
	scanf("%d",&m);
	for(int i=0; i<m; i++) {
		int x;
		
		scanf("%d",&x);
		if(x>0){
			xx++;
		}else if(x<0){
			yy++;
		}
		v2.emplace_back(x);
	}
	u=min(u,xx);
	v=min(v,yy);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<v;i++){
		sum+=v1[i]*v2[i];
	}
	int idx1=v1.size()-1;
		int idx2=v2.size()-1;
	for(int i=0;i<u;i++,idx1--,idx2--){
		sum+=v1[idx1]*v2[idx2];
	}
	cout<<sum;
	
	
}
