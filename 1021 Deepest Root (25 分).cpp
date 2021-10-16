
#include<bits/stdc++.h>
using namespace std;

// 连通块数量
const int MAX_NODE_CNT=11111;
bool vis[MAX_NODE_CNT];
vector<int>g[MAX_NODE_CNT];
int n;
int dep[MAX_NODE_CNT];
void dfs(int u){
    vis[u]=true;
//     if(g[u].size()==0)return;
//     加了这句也没用
    for(int v:g[u]){
        if(vis[v])continue;
//         vis[v]=true;
        dfs(v);
    }
}

void deepDfs(int u,int depth,int now){
        vis[now]=true;
       dep[u]=max(dep[u],depth+1);
    for(int v:g[now]){
        if(vis[v])continue;
//         vis[v]=true;
//         depth++;
     
        deepDfs(u,depth+1,v);
    }
}

int main(){
    scanf("%d",&n);
//     n-1 边
    for(int i=1;i<n;i++){
//         he nodes are numbered from 1 to N. T
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].emplace_back(v);
           g[v].emplace_back(u);
    }
    
    int compCnt=0;
//     he nodes are numbered from 1 to N. T
    for(int u=1;u<=n;u++){
     
        if(vis[u])continue;
        compCnt++;
//            vis[u]=true;
        dfs(u);
    }
    if(compCnt>1){
        printf("Error: %d components\n",compCnt);
        return 0;
    }
    
        for(int u=1;u<=n;u++){
     fill(vis,vis+n+1,false);
//         if(vis[u])continue;

//            vis[u]=true;
        deepDfs(u,0,u);
    }
    int maxIndex=1;
     for(int u=1;u<=n;u++){
         if(dep[u]>dep[maxIndex]){
             maxIndex=u;
         }
     }
     for(int u=1;u<=n;u++){
         if(dep[u]==dep[maxIndex]){
             printf("%d\n",u);
         }
     }
    
}
