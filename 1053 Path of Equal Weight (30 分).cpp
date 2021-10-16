//1053 Path of Equal Weight (30 分)
#include <bits/stdc++.h>
using namespace std;
const int MAX_NODE_CNT=1111;
int nodeCnt,noLeCnt,totWei;
int we[MAX_NODE_CNT];
vector<int>g[MAX_NODE_CNT];
vector<int>path;
//a 
//vector<int>pathRes;
//https://blog.csdn.net/qq_37613112/article/details/101107444
typedef vector<int> Path;
vector<Path>pathResls;

void printV(Path v) {
	int fir=1;
	for(auto val:v) {
		if(fir)fir=0;
		else printf(" ");
		cout<<val;
	}
	printf("\n");
}

//遍历所有路径 
void dfs(int u,int nowWei) {

	if(nowWei==totWei) {
		if(g[u].size())return;
		//如果此时权值相等还有子树，那么到叶节点时权值一定会大于s 
		printV(path);
	}

//还有一些剪枝
	if(u>=nodeCnt||nowWei>totWei)return;
	for(int v:g[u]) {
		path.push_back(we[v]);
		dfs(v,nowWei+we[v]);
		path.pop_back();
	}

}
bool cmpVec(Path a,Path b) {
	for(int i=0; i<a.size(); i++) {
		if(a[i]!=b[i]) {
			return a[i]>b[i];
		}
	}
	return true;
}

bool cmp(int a,int b) {
	return we[a]>we[b];
}
int main() {
	scanf("%d%d%d",&nodeCnt,&noLeCnt,&totWei);
	for(int i=0; i<nodeCnt; i++) {
		scanf("%d",we+i);
	}
	for(int i=0; i<noLeCnt; i++) {
		int u;
		int vCnt;
		scanf("%d %d",&u,&vCnt);
		for(int j=0; j<vCnt; j++) {
			int v;
			scanf("%d",&v);
			g[u].push_back(v);
		}

		sort(g[u].begin(),g[u].end(),cmp);
//		printf("=====\n");
//		printf("g[u]\n");
//		printV(g[u]);
	}
//	一开始也要push
	path.push_back(we[0]);
//	一开始的wei 不是0
	dfs(0,we[0]);
//	sort(pathResls.begin(),pathResls.end(),cmpVec);
//	printf("out\n");
//	for(auto v:pathResls) {
//		printV(v);
//	}


}
