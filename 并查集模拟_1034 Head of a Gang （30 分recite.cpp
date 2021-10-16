
#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int n,k;
int index1=0;
const int MAX_PER_CNT=2007;

struct Person {
	string name;
	int len;
//	Person() : name(name) ,len(len) {
//
//	}

};
int f[MAX_PER_CNT];
void init() {
	for(int i=0; i<MAX_PER_CNT; i++) {
		f[i]=i;
	}
}
int find(int x) {
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
vector<Person>pers;
void unite(int  idx1,int  idx2) {
//	int idx1=mp[na1];
//		int idx2=mp[na2];
	int fx=find(idx1);
	int fy=find(idx2);
//		fx 大
if(fx==fy)return; 
	if(pers[fx].len>pers[fy].len) {
		f[fy]=fx;

	} else {
		f[fx]=fy;
	}

}

vector<pair<string,string> >pairs;
int num[MAX_PER_CNT];
//vector<Person>okPers;
vector<string>okPers;
int main() {
	init();
	scanf("%d%d",&n,&k);
	pers.resize(MAX_PER_CNT);
//	https://zhidao.baidu.com/question/458289149.html
	for(int i=0; i<n; i++) {
		string name1,name2;
		int ti;
//		char name1[3213];
//		scanf("%s",name1);

		cin>>name1>>name2>>ti;
		if(mp[name1]==0) {
			mp[name1]=++index1;
			pers[index1].name=name1;
			pers[index1].len=ti;

		} else {
			pers[mp[name1]].len+=ti;
		}
		if(mp[name2]==0) {
			mp[name2]=++index1;
			pers[index1].name=name2;
			pers[index1].len=ti;

		} else {
			pers[mp[name2]].len+=ti;
		}
		auto p= make_pair(name1,name2);
		pairs.push_back(p);
	}
	for(auto p: pairs) {
		unite(mp[p.first],mp[p.second]);
	}
	for(int i=1; i<=index1; i++) {
		int bro=find(i);
//		if(bro!=i){
//这里不管 哪种都是错的 
		if(f[i]!=i){
				pers[bro].len+=pers[i].len;
		}
//	每次有一个人发现是这个老大 他就++ 
		num[bro]++;
	}
	for(int i=1; i<=index1; i++) {
		if(num[i]>2&&pers[i].len>2*k) {
//			auto p= Person();
//			p.name=pers[i].name;
//			p.len=pers[i].len;
//			okPers.push_back(p);
				okPers.push_back(pers[i].name);
//			okPers.emplace_back(pers[i].name,pers[i].len);
		}
	}
	printf("%d\n",okPers.size());
//	for(auto p:okPers) {
//		cout<<p.name<<" "<<p.len<<"\n";
//	}
//忘记sort 了 
 sort(okPers.begin(),okPers.end());
	for(auto p:okPers) {
		cout<<p<<" "<<num[mp[p]]<<"\n";
	}
}
