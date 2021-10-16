#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	string shop,eva;
	map<char,int> mp;
	mp.clear();   //默认初始化为0 
	cin>>shop>>eva;
	for(int i=0;i<shop.size();i++){
		mp[shop[i]]++; 
	}
	int flag=0,lack=0;
	for(int j=0;j<eva.size();j++){
		if(mp[eva[j]] < 1) {
			lack++;
			flag = 1;
		}
//		要拼出 项链 
		mp[eva[j]]--;
		cout<<"mp[eva[j]] eva[j]  "<<mp[eva[j]]<<" "<<eva[j]<<"\n";
	}
	int exceed=0;
	if(flag){
		printf("No %d\n",lack);
	}else{
//		剩下 
		for(auto it: mp){
			cout<<"have "<< it.second<<"\n" ;
			exceed += it.second;
		}
		printf("Yes %d\n",exceed);
	}
	return 0;
} 

