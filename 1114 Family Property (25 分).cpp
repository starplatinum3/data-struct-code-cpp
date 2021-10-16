#include<bits/stdc++.h>
using namespace std;
int n;
class Fami {
	public:
		int id,fa,ma;
		vector<int>ch;
		set<int>pers;
		double sets,area;
		double avs,ava;
		int persiz;
		Fami() {
		}
		Fami(int id,int fa,int ma):
			id(id),fa(fa),ma(ma) {
//			pers.add(id);
//			pers.add(fa);
//			pers.add(ma);
//
//				pers.push(id);
//			pers.push(fa);
//			pers.push(ma);
			if(id!=-1)
				pers.insert(id);
			if(fa!=-1)
				pers.insert(fa);
			if(ma!=-1)
				pers.insert(ma);
		}
		void add(Fami fami) {
			sets+=fami.sets;
			area+=fami.area;
			for(auto p:fami.pers) {
				pers.insert(p);
			}
		}

		void print() {
			cout<<id<<" id"<<"\n";
			printf("%04d %d %.3f %.3f\n",id,pers.size(),
			       sets/pers.size(),area/pers.size());
		}

		void printWithoutId() {
//			cout<<id<<" id"<<"\n";
			printf("%d %.3f %.3f\n",pers.size(),
			       sets/pers.size(),area/pers.size());
		}
		void refresh() {
			persiz=pers.size();
			avs=sets/persiz;
			ava=area/persiz;
		}
};
const int N=10000;
Fami fami[N];
int f[10000];
int find(int x) {
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
void unite(int x,int y) {
	if(y==-1)return;
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy) {
		if(fx<fy) {
			f[fy]=fx;
		} else {
			f[fx]=fy;
		}
//		所有儿子都要合并
//		小的 作为 老大
	}
}

void init() {
	for(int i=0; i<10000; i++) {
		f[i]=i;
	}
}

class Res {
	public:
		int id,cnt;
		double avs,ava;
		Res(	int id,int cnt,
		        double avs,double ava):
			id(id),cnt(cnt),avs(avs),
			ava(ava) {

		}

		Res(	int id,Fami f):
			id(id) {
			f.refresh();
			avs=f.avs;
			cnt=f.persiz;
			ava=f.ava;
		}

		bool operator<(const Res&rhs ) const {
			if(ava!=rhs.ava) {
				return ava>rhs.ava;
			}
			return id<rhs.id;
		}
		void print() {
			printf("%04d %d %.3f %.3f\n",id,cnt,
			       avs,ava);
		}

};
int vis[N];
vector<Res>ress;
//a 
int main() {
	scanf("%d",&n);
	init();
	for(int i=0; i<n; i++) {
		int id,fa,ma;
		scanf("%d%d%d",&id,&fa,&ma);
		int chCnt;
		scanf("%d",&chCnt);
		fami[id]=Fami(id,fa,ma);
		unite(id,fa);
		unite(id,ma);
		vis[fa]=vis[ma]=1;
		for(int j=0; j<chCnt; j++) {
			int x;
			scanf("%d",&x);
			vis[x]=1;
			fami[id].pers.insert(x);
			unite(id,x);
		}
		double sets,area;
		scanf("%lf%lf",&sets,&area);
		fami[id].sets=sets;
		fami[id].area=area;

		vis[id]=1;
	}

//有可能是0 的id 嘛? 
//是的 就是因为有id ==0 的情况 我没写 
	for(int i=0; i<=9999; i++) {
		int fi=find(i);
//		这没说是自己家的人啊 怎么可以直接加
//可以的 啊 fi 是通过i 找到的 就是自己家人 
		if(fi!=i) {
			fami[fi].add(fami[i]);
		}
	}

	for(int i=0; i<=9999; i++) {
		int fi=find(i);
		if(fi==i&&vis[i]) {
//			printf("fi %d\n",fi);
//			printf("%04d ",fi);
//			printf("%04d %d %.3f %.3f\n",)
//			fami[fi].printWithoutId();
			ress.emplace_back(fi,fami[fi]);
		}
	}
	sort(ress.begin(),ress.end());
	printf("%d\n",ress.size());
	for(auto re:ress) {
		re.print();
	}

}
