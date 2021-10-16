#include<cstdio>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
//题目都没看懂, 看了博客 
//https://blog.csdn.net/galesaur_wcy/article/details/81910895
//才读懂 

//thiiis iiisss a teeeeeest
//虽然s 也是出现了 sss这种多个的 ,但是也有s这种单个的 
//如果s 坏了的话 就一定只能是sss这种多个的,而且
//必须是给的n个,比如样例的3个.
//3的倍数 也可以的, 因为相当于这三个过去之后,又按了一下按键
//然后又跳出3个 
// 不会出现  单个的s
//
//所以有哪些是连续3个的就是了

int n;
string s;
int same(int & idx) {
	int cnt=0;
	for(int i=idx; i<s.length(); i++) {
		if(s[idx]==s[i]) {
			cnt++;
		} else {
			break;
		}
	}
//	 3 % 3==0
//2 %3
//printf("\n");
//printf("cnt mod n== %d s[idx] ==%c\n",cnt%n,s[idx]);
	idx+=cnt;
//	printf("cnt mod n== %d s[idx] ==%c\n",cnt%n,s[idx]);
// sss  这种是0 的  需要cut 。
// 但是 如果有 ss 不是 n的倍数的 那就不用cut 了
	return cnt%n;
}

int shoc[331];
unordered_set<char>shoCut;
vector<char>shoCutV;
vector<char> uni(vector<char>v) {
	vector<char>res;
	for(auto val:v) {
		if(find(res.begin(),res.end(),val)==res.end()) {
//			cout<<val<<"\n";
			res.push_back(val);
		}

	}
	return res;
}
int main() {
	cin>>n>>s;
//	for(char c:s) {
//		shoc[c]=1;
//	}
//i++
	for(int i=0; i<s.length(); ) {
//		0 就是sss 这样的需要改变的
		char ch=s[i];
		if(same(i)==0) {
			shoc[ch]=1;
		}
	}

//i++
	for(int i=0; i<s.length(); ) {
//		0 就是sss 这样的需要改变的
		char ch=s[i];
//		same引用传值  会变化
		if(same(i)!=0) {
			shoc[ch]=0;
		}
	}


	for(char c:s) {
		if(shoc[c]==1) {
//			shoCut.insert(c);
			shoCutV.push_back(c);
		}
	}
//	auto it=unique(shoCutV.begin(),shoCutV.end());
	shoCutV=uni(shoCutV);
//https://www.cnblogs.com/lx17746071609/p/13717115.html
//  shoCutV.erase(it,shoCutV.end());
//    shoCutV.erase(it-1,shoCutV.end());
	for(char c:shoCutV) {
		cout<<c;
	}
	printf("\n");
	for(int i=0; i<s.length();) {
		cout<<s[i];
		if(find(shoCutV.begin(),shoCutV.end(),
		        s[i])!=shoCutV.end()) {
			i+=n;
		} else {
			i++;
		}

//		if(shoCut.find(s[i])!=shoCut.end()) {
//			i+=n;
//		} else {
//			i++;
//		}

	}


}
