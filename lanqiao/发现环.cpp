#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100000+5;
int f[N], vis[N], idx;
vector<int> g[N], ans;
 
int find(int x){
	return x == f[x] ? x : f[x] = find( f[x]);
}
 
bool dfs(int u){
    // 从3 开始 到3 结束
    // 连接成一个环了
	if(vis[u]){
		if(u == idx) return true;
		return false;
	}
	vis[u] = 1;
    // 和3 相连的
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if( dfs(v) ){
			ans.push_back(v);
			return true;
		} 
	}
	return false;
}

// https://blog.csdn.net/qq_42835910/article/details/88143920
int main(int argc, char *argv[]) {
	int n;
	cin>> n;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= n; i++){
		int u, v;
		cin>> u>> v;
		g[u].push_back(v);
		g[v].push_back(u);
        // 1 2 
        // 1 2 5
        // 1 2 5 3
        //  1 2 5 3 1
        //  走到1 3 的时候，发现连接过了 
        //  说明是环了，就从他开始
		int x = find(u), y =find(v);
		if( x != y){
			f[x] = y;			
		}else{
			idx = u;
			dfs(u);
            // 3
		} 
	}
	sort( ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) 
    cout<< ans[i]<< " ";
	return 0;
}