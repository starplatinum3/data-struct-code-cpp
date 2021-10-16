//1041 Be Unique (20 ·Ö)
#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
//1040 Longest Symmetric String (25 ·Ö)
//https://blog.csdn.net/weixin_42582136/article/details/90291680
using namespace std;
int n;
const int MAX_NUM=100007;
bool vis[MAX_NUM];
bool vis2[MAX_NUM];
vector<int>v;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(vis[x]){
			vis2[x]=true;
		}
		vis[x]=true;
		v.push_back(x);
	}
	
	int have=0; 
	for(int val:v){
		if(!vis2[val]){
				printf("%d\n",val);
				have=1;
				break;
		}
	
		
	}
	if(!have){
		printf("None\n");
	}
	
}
