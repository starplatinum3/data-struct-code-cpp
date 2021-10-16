//
// Created by Lenovo on 2020/12/17.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxm 50005
#define maxn 10005
using namespace std;
int n, m;
struct edge {
    int next, to;
    bool vis;
} edges[maxm * 2];
int cnt;
int head[maxn];

void addedge(int u, int v) {
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
//O n^2 的
//https://blog.csdn.net/qq_43733499/article/details/103935245
void euler(int u) {
    for (int i = head[u]; i != -1; i = edges[i].next)
        if (!edges[i].vis) //虽说是无向图 但是他说要两个方向都走 走第一次的时候一个方向
//走掉了 但是另外一个方向还可以走 所以就直接这样就行
        {
            edges[i].vis = true;
            euler(edges[i].to);
        }
    printf("%d\n", u);
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);

    }
    euler(1);
    return 0;
}