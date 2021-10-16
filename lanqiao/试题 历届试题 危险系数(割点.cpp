//
// Created by Lenovo on 2021/2/23.
//

//https://www.cnblogs.com/mohari/p/13509803.html

#include<bits/stdc++.h>
using namespace std;

vector<int>d[1005];
int way[1005],cnt[1005],vis[1005];///记录该路径数点的出现次数。
int n,m,u,v,sum;

#include "util/printUtilNotClass.h"
void dfs(int u,int depth){
    way[depth]=u;

    printf("way\n");
    printArr(way,depth+1);

//    这个是在dfs 中 在判断 ，那么是每次都出现的点吗
    if(u==v){
//        这个是他走到终点才会有一次的
        sum++;///路径数
//        这条路的每一个数字都记录++
//        1    3    4    5    6

//然后另外一条路
//        1    3    5    6
//每一个 cnt ++
        for(int i=0;i<=depth;i++){///经过的点数
            cnt[way[i]]++;
            printf("point : %d, cnt: %d\n",way[i],cnt[way[i]]);
//            到某个点的路径是 cnt 条
        }
        return ;
    }
    for(int i=0;i<d[u].size();i++){
        if(vis[d[u][i]]==0){
            vis[d[u][i]]=1;
            dfs(d[u][i],depth+1);
            vis[d[u][i]]=0;
        }
    }
}
int check(){
    int ans=0;
//    每个点 去看看， 如果点经过的次数和路径的条数是一样的话，说明
//每次都经过这个点了，所以是必经点
    for(int i=1;i<=n;i++){
        ///cout<<i<<" "<<cnt[i]<<endl;
        if(cnt[i]==sum){
            ans++;
        }
//        对上了就是一个
    }
    ans-=2;
//    除去 开始和结束的点
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        d[u].push_back(v);
        d[v].push_back(u);
    }
    cin>>u>>v;
    vis[u]=1;
    dfs(u,0);
    if(check()<0)cout<<"-1"<<endl;
    else cout<<check()<<endl;
    return 0;
}