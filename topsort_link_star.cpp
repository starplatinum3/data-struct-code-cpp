//
// Created by Lenovo on 2020/11/19.
//

//拓扑排序
//        应用
//1.如果成环了
//2 . 确定比赛名次  因为没有前驱的肯定是最强的

#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000007;
struct node{
    int to,nxt;
}e[maxn];
int ind[maxn],head[maxn],tot;
void add(int u,int v){
    e[tot].nxt=head[u];
    e[tot].to=v;
    head[u]=tot++;
}
queue<int> q;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) head[i]=-1;
    for(int i=0;i<m;i++){
        int a,b;scanf("%d%d",&a,&b);
        add(a,b);
//        连边
        ind[b]++;
//        b的入度++
    }
    for(int i=1;i<=n;i++){
        if(!ind[i]) q.push(i);
//        没有入度的 push ，就是出去了
    }
    while(!q.empty()){
//        queue<int> q;
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=e[i].nxt){
            int to=e[i].to;
            ind[to]--;
            if(!ind[to]) q.push(to);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!ind[i]) cnt++;
//        没有入度的 有几个
    }
//    如果全部出来了
    if(cnt==n) printf("Keadin NB!\n");//没有环
    else printf("Oh, it's too messy!\n");//有环
    return 0;
}