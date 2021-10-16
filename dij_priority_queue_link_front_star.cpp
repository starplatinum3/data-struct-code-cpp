//
// Created by Lenovo on 2020/11/12.
//
//P3371 【模板】单源最短路径（弱化版）
//应该是对的
#include <bits/stdc++.h>

using namespace std;
const long long INF = (1 << 31) - 1;
const int N = 5e5 + 10;
struct edge {
    int v, w, next;
} e[N];

struct node {
    int dis, id;

    bool operator<(const node &a) const {
        return dis > a.dis;
    }

    node(int d, int x) {
        dis = d;
        id = x;
    }
};

int head[N], vis[N];
int cnt, n, m;
long long dis[N];

void addedge(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra(int s) {
    priority_queue<node> q;
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
//              dis,id;
    q.push(node(0, s));
    while (!q.empty()) {
        int u = q.top().id;
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
//                到v点的最小距离是dis[v]，暂时
                if (!vis[v])q.push(node(dis[v], v));
            }
        }
    }

}


int main() {
    int s,u,v,w;
    int end;

    scanf("%d%d%d",&n,&m,&s);

    scanf("%d",&end);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
//        无向图
        addedge(u,v,w);
        addedge(v,u,w);
    }

    // spfa(s);
    dijkstra(s);
//    for(int i=1;i<=n;i++)
//    {
//        printf("%d ",dis[i]);
//    }
//从起点到终点的 最短距离
    printf("%lld\n", dis[end]);

    return 0;
}