
// Created by Lenovo on 2020/12/17.
//
#include <bits/stdc++.h>

const int N = 1e3 + 7;
int a[N];
int e[N][N];

int f[N];

void init() {
  for (int i = 0; i < N; i++) {
    f[i] = i;
  }
}

int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}

void unite(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx != fy) {
    // fy 是爹
    f[fx] = fy;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  init();
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u][v] = 1;
    e[v][u] = 1;

    unite(u, v);
  }
  //    https://www.jb51.net/article/157307.htm

  int odd = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    // 对于每一个点 去数一数和她相邻的有几个链接的路
    //        https://www.cnblogs.com/asdfknjhu/p/13081167.html
    for (int j = 1; j <= n; j++) {
      cnt += e[i][j];
    }
    // 如果连接的点数是奇数的话，odd++
    if (cnt % 2) {
      odd++;
    }
  }

  //   如果一个点和其他点相连是奇数，这样的点是0个或者2个的话，是可以一笔画的。

  if (odd != 0 && odd != 2) {
    printf("N");
    return 0;
  }

  //   还要判断一下图是不是联通，可以用并查集判断，如果所有点的爹都是同一个的话，那就是联通的
  int rootCnt = 0;

  for (int i = 1; i <= n; i++) {
    if (i == find(i)) {
      rootCnt++;
    }
  }
  if (rootCnt == 1)
    printf("Y");
  else
    printf("N");
}