#include<cstdio>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
//��Ŀ��û����, ���˲��� 
//https://blog.csdn.net/galesaur_wcy/article/details/81910895
//�Ŷ��� 

//thiiis iiisss a teeeeeest
//��Ȼs Ҳ�ǳ����� sss���ֶ���� ,����Ҳ��s���ֵ����� 
//���s ���˵Ļ� ��һ��ֻ����sss���ֶ����,����
//�����Ǹ���n��,����������3��.
//3�ı��� Ҳ���Ե�, ��Ϊ�൱����������ȥ֮��,�ְ���һ�°���
//Ȼ��������3�� 
// �������  ������s
//
//��������Щ������3���ľ�����

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
// sss  ������0 ��  ��Ҫcut ��
// ���� ����� ss ���� n�ı����� �ǾͲ���cut ��
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
//		0 ����sss ��������Ҫ�ı��
		char ch=s[i];
		if(same(i)==0) {
			shoc[ch]=1;
		}
	}

//i++
	for(int i=0; i<s.length(); ) {
//		0 ����sss ��������Ҫ�ı��
		char ch=s[i];
//		same���ô�ֵ  ��仯
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
