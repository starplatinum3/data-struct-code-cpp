//1037 Magic Coupon (25 ·Ö)
#include<bits/stdc++.h>
using namespace std;
vector<int>v1,v2;
const int MAX_SIZE=100006;
bool vis1[MAX_SIZE],vis2[MAX_SIZE];
int sum=0;
//void fin(int i) {
//	for(int j=0; j<v2.size(); j++) {
//		if(vis2[j])continue;
//		if(v1[i]*v2[j]>0) {
//			vis1[i]=true;
//			vis2[j]=true;
//			sum+=v1[i]*v2[j];
//		}
//	}
//}

//time out
void printV(vector<int>v){
	for(auto val:v){
		cout<<val<<" ";
	}
	putchar('\n');
}
int main() {
	int n,m;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d",&x);
		v1.emplace_back(x);
	}
	scanf("%d",&m);
	for(int i=0; i<m; i++) {
		int x;
		scanf("%d",&x);
		v2.emplace_back(x);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
//	printV(v1);
//		printV(v2);
	int j=0;
	int i=0;
	for(; i<v1.size(); ) {
		if(v1[i]>0)break;
		int shob=0;
		for(; j<v2.size(); j++) {
			if(v2[j]>0){
				shob=1;
				break;
			}
			if(vis2[j])continue;
			
			if(v1[i]*v2[j]>0) {
				vis1[i]=true;
				vis2[j]=true;
			
				sum+=v1[i]*v2[j];
//				printf("v1 v2 ,%d ,%d\n",v1[i],v2[j]);
					i++;
			}
		}
		
		if(shob){
			break;
		}
	}

//printf("big\n");
	for(i=v1.size()-1; i>=0;) {
		if(vis1[i])break;
		if(v1[i]<0)break;
		int shob=0;
		for(j=v2.size()-1; j>=0; j--) {
			
			if(v2[j]<0)break;
			if(vis2[j]){
				shob=1;
				break;
			}
			
			if(v1[i]*v2[j]>0) {
				vis1[i]=true;
				vis2[j]=true;
			
//					printf("v1 v2 ,%d ,%d\n",v1[i],v2[j]);
				sum+=v1[i]*v2[j];
					 i--;
			}
		}
		if(shob){
			break;
		}
	}

	cout<<sum;
}
