//1035 Password (20 ·Ö)
#include<bits/stdc++.h>
using namespace std;
//a
vector<string>strs;
int n;
int make(string &s){
	int have=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			s[i]='@';
			have=1;
		}
		else if(s[i]=='0'){
			s[i]='%';
			have=1;
		}
		else if(s[i]=='l'){
			s[i]='L';
			have=1;
		}
		else if(s[i]=='O'){
			s[i]='o';
			have=1;
		}
	}
	return have;
}
int md=0;
struct StrMd{
	string str;
	string team;
	int md;
};
vector<StrMd>v;
int main(){

	cin>>n;
	for(int i=0;i<n;i++){
			string str,team;
		cin>>team>>str;
		int md1=make(str);
		md+=md1;
		auto sm=StrMd();
		sm.str=str;
		sm.md=md1;
		sm.team=team;
		v.push_back(sm);
	}
	if(n==1){
		if(md==0){
			printf("There is 1 account and no account is modified\n");
		}else{
			printf("1\n");
			for(auto sm:v){
				if(sm.md==1){
					cout<<sm.team<<" "<<sm.str<<"\n";
				}
			}
		}
	}else{
		if(md==0){
			printf("There are %d accounts and no account is modified\n",n);
		}
		else{
				printf("%d\n",md);
		for(auto sm:v){
				if(sm.md==1){
					cout<<sm.team<<" "<<sm.str<<"\n";
				}
			}
		}
	
	}
} 
