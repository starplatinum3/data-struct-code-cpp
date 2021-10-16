//1040 Longest Symmetric String (25 ·Ö)

#include<iostream>
#include<algorithm>
#include<string>
//1040 Longest Symmetric String (25 ·Ö)
//https://blog.csdn.net/weixin_42582136/article/details/90291680
using namespace std;
	string s;
int lenSymmetricString(int st,int ed){
//	int st=idx,ed=idx;
   	for(;ed<s.length()&&st>=0&&s[st]==s[ed];st--,ed++);
   	return ed-st-1;
}

//string s
int maxNum=0;
int longestSymmetricStringLen(){
	for(int i=0;i<s.length();i++){
		int tmpMax=max(lenSymmetricString(i,i),lenSymmetricString(i,i+1));
		maxNum=max(maxNum,tmpMax);
	}
	return maxNum;
}
int main(){

	getline(cin,s);
	int len=longestSymmetricStringLen();
	cout<<len;
}
