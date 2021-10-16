//1093 Count PAT's (25 ·Ö)
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
const int N=1e7;
int t[N],p[N];
long long sum=0;
long long  mod=1000000007;
//ac 

int main(){
	cin>>s;
	p[0]=s[0]=='P'?1:0;
	for(int i=1;i<s.length();i++){
		p[i]=p[i-1];
		if(s[i]=='P'){
			p[i]++;
		}
	}
	int len=s.length();
	t[len-1]=s[len-1]=='T'?1:0;
		for(int i=len-2;i>=0;i--){
		t[i]=t[i+1];
		if(s[i]=='T'){
			t[i]++;
		}
		else if(s[i]=='A') 
		sum=(sum+t[i]*p[i])%mod;
	}
	cout<<sum;
}
