
#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<int,int>line;
int st,ed;
int k;
const int N=1e5+10;
int vis[N];
vector<int>pa,tmp,g[N];
int idx(int i,int j) {
	return i*100000+j;
}
const int INF=0x3f3f3f3f;
int miTran=INF;
int miDis=INF;
void dfs(int u,int d) {
	if(u==ed) {
//		printf("d %d\n",d);
		int cnt=0;
		for(int i=0; i<tmp.size()-2; i++) {
			if(line[idx(tmp[i],tmp[i+1])]!=
			        line[idx(tmp[i+1],tmp[i+2])]) {
				cnt++;
			}
		}
		if(d<miDis) {
			miTran=cnt;
			pa=tmp;
			miDis=d;
		} else if(d==miDis&&cnt<miTran) {
			miTran=cnt;
			pa=tmp;
			miDis=d;
		}
		return ;
	}
	for(int v:g[u]) {

		if(vis[v])continue;
//		printf("v %d\n",v);
		tmp.push_back(v);
		vis[v]=1;
		dfs(v,d+1);
		tmp.pop_back();
		vis[v]=0;
	}
}

int li(int i,int j){
	return line[idx(i,j)];
}

void printPa(vector<int>pa){
	for(int v:pa){
		cout<<v<<" ";
	}
	cout<<"\n";
}
void print(){
	printf("%d\n",miDis);
	int i,j;
	i=0;
//	printPa(pa);
	for(j=1;j<pa.size();j++){
		if(li(pa[j-1],pa[j])!=li(pa[j],pa[j+1])){
			printf("Take Line#%d from %04d to %04d.\n",
			li(pa[j-1],pa[j]),pa[i],pa[j]);
			i=j;
			j=i;
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int z=0; z<n; z++) {
		int m;
		scanf("%d",&m);
		vector<int>a;
		for(int j=0; j<m; j++) {
			int x;
			scanf("%d",&x);
			a.push_back(x);
//			line[x]

		}
		for(int i=0; i<a.size()-1; i++) {
			line[a[i]*100000+a[i+1]]=
			    line[a[i+1]*100000+a[i]]=z+1;
			    g[a[i]].push_back(a[i+1]);
			     g[a[i+1]].push_back(a[i]);
		}
	}
	scanf("%d",&k);
	for(int i=0; i<k; i++) {
		scanf("%d%d",&st,&ed);
		fill(vis,vis+N,0);
		tmp.clear();
//		不清空的话 之前的第一个会在 
		tmp.push_back(st);
		miDis=INF;
		 miTran=INF;
		vis[st]=1;
		dfs(st,0);
			print();
	}

}
