//1047 Student List for Course (25 ·Ö)
#include<bits/stdc++.h>
using namespace std;
const int MAX_CO_CNT=2555;
class Cou{
	public:
	vector<string>stus;
	int num;
	Cou(int num, vector<string> stus): 
	num(num),stus(stus) {
		
	}
	
	Cou(int num): 
	num(num){
		
	}
	
	Cou()
	{
		
	}
};
Cou cous[MAX_CO_CNT];
int n,m,k;
void printV(vector<string>v){
	sort(v.begin(),v.end());
	for(auto val:v){
		cout<<val<<"\n";
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<MAX_CO_CNT;i++){
		cous[i]=Cou(i);
	}
	for(int i=0;i<n;i++){
	  string name;
	  int coNum;
	  cin>>name>>coNum;
	  for(int j=0;j<coNum;j++){
	  	int co;
	  	cin>>co;
	  	cous[co].stus.push_back(name);
	  }
	}
	
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,cous[i].stus.size());
		printV(cous[i].stus);
	}
	
}
