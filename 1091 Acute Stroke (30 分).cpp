
#include <bits/stdc++.h>
using namespace std;

int n, m, l, k;
int stx, sty, stz;
class State {
 public:
  int x, y, z;
  State(int x, int y, int z) : x(x), y(y), z(z) {}
  State() {}
};
const int N = 1300;
int vis[N][130][66];
int g[N][130][66];
int dirx[] = {0, 0, 0, 0, 1, -1};
int diry[] = {0, 0, 1, -1, 0, 0};
int dirz[] = {1, -1, 0, 0, 0, 0};
int check(State st) {
  if (st.x < 0 || st.x >= n || st.y < 0 || st.z < 0 || st.y >= m || st.z >= l)
    return 0;
  if (vis[st.x][st.y][st.z]) return 0;
  return g[st.x][st.y][st.z];
  //	return 1;
}
//	int cnt=0;
int ans = 0;
int bfs(int stx, int sty, int stz) {
  State st = State(stx, sty, stz);
  //	State st=State(0,0,0);
  queue<State> q;
  q.push(st);
  vis[stx][sty][stz] = 1;
  int cnt = 0;
  while (!q.empty()) {
    cnt++;
    State fr = q.front();
    q.pop();
    for (int i = 0; i < 6; i++) {
      State ne = State(fr.x + dirx[i], fr.y + diry[i], fr.z + dirz[i]);
      if (check(ne)) {
        vis[ne.x][ne.y][ne.z] = 1;
        q.push(ne);
      }
    }
  }
  printf("stx %d  sty %d stz %d cnt %d\n", stx, sty, stz, cnt);
  if (cnt >= k) return cnt;
//   联通的点  超过k 算是一块瘤
  return 0;
}
int main() {
  //	int val=12+6+2+2+2;
  //	printf("%d\n",val);
  scanf("%d%d%d%d", &n, &m, &l, &k);
  for (int z = 0; z < l; z++) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        scanf("%d", &g[x][y][z]);
      }
    }
  }

  for (int z = 0; z < l; z++) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        auto st = State(x, y, z);
        if (check(st)) {
          ans += bfs(x, y, z);
        }
      }
    }
  }

  printf("%d\n", ans);

  //	printf("%d\n",ans);
}
