

void dfs(int u){
    for(int v:g[u]){
        if(vis[v])continue;
        vis[v]=1;
        dfs(v);
    }
}

int main(){

int partCnt=0;
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        partCnt++;
        vis[i]=1;
        dfs(i);
    }
}