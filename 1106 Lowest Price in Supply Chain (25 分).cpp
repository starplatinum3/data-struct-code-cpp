#include<bits/stdc++.h>
using namespace std;
int n;
double p,r;
const int N=1e5+7;
vector<int>g[N];
const int INF=0x3f3f3f3f;
void printG() {
	for(int i=0; i<n; i++) {
		for(auto val:g[i]) {
			printf("%d %d\n",i,val);
		}

	}
	printf("\n");
}
class Node {
	public:
		int id,dep;
		Node(int id,int dep):
			id(id),dep(dep) {
		}
};

int miDep=INF;
//vector<int>deps[N];
int deps[N];
void bfs () {
	queue<Node>q;
	q.push({0,0});
	while(!q.empty()) {
		Node fr=q.front();
		q.pop();
		int u=fr.id;
		int dep=fr.dep;
//		printf("u %d\n",u);
		if(g[u].size()==0) {
			miDep=min(miDep,dep);
//			deps[dep].push_back
			deps[dep]++;
		}
		for(int v:g[u]) {
//  if(vis[v])continue;
			q.push({v,dep+1});
		}


	}
}
//树的最深处  应该最不深处
//但是一定是树嘛 应该是吧,因为说是从suppliers来的嘛
int main() {
//  double val=	1.8*101/100*101/100;
//  cout<<val<<"\n";
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0; i<n; i++) {
		int k;
		scanf("%d",&k);
		for(int j=0; j<k; j++) {
			int x;
			scanf("%d",&x);
			g[i].push_back(x);
		}
	}
	bfs();
	double res=p*pow((100+r)/100,miDep);
	printf("%.4f %d\n",res,deps[miDep]);
//	printG();
}
