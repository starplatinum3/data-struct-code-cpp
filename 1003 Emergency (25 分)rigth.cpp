// 1003 Emergency (25 分)

#include <bits/stdc++.h>
using namespace std;

int n, m, st, en;
const int N = 555;
int re[N];
int len[N][N];
vector<int> g[N];
int dis[N];
const int INF = 0x3f3f3f3f;
int vis[N], res[N];
int paCnt = 1;
int roCnt[N];
class Node {
 public:
  int len, id;
  Node(int len, int id) : len(len), id(id) {}
  Node() {}
  bool operator<(const Node &rhs) const { return len > rhs.len; }
};
// ac
void dij() {
  fill(dis, dis + N, INF);
  dis[st] = 0;
  res[st] = re[st];
  roCnt[st] = 1;
  priority_queue<Node> q;
  q.push({0, st});
  //	一开是 是re个
  while (!q.empty()) {
    Node fr = q.top();
    q.pop();

    int u = fr.id;
    if (vis[u]) continue;
    vis[u] = 1;
    for (int v : g[u]) {
      if (vis[v]) continue;

      if (dis[v] > dis[u] + len[u][v]) {
        dis[v] = dis[u] + len[u][v];
        res[v] = res[u] + re[v];
        roCnt[v] = roCnt[u];
        	// u 是有了 ，v是还没有 要试试
        //				paCnt=1;
        //				printf("more short path cnt
        //%d\n",paCnt); 				printf("v: %d u %d\n",v,u);
      } else if (dis[v] == dis[u] + len[u][v]) {
        if (res[v] < res[u] + re[v]) {
          res[v] = res[u] + re[v];
        }
        //			          	printf("v %d u %d\n",v,u);

        //				paCnt++;
        roCnt[v] += roCnt[u];
        //				printf("more path cnt %d\n",paCnt);
      }

      q.push({dis[v], v});
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &st, &en);
  for (int i = 0; i < n; i++) {
    scanf("%d", re + i);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      len[i][j] = INF;
    }
  }
  for (int i = 0; i < m; i++) {
    int u, v, leng;
    scanf("%d%d%d", &u, &v, &leng);
    len[u][v] = len[v][u] = leng;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dij();
  printf("%d %d\n", roCnt[en], res[en]);
  //	printf("dis[en] %d\n",dis[en]);
}
