//1003 Emergency (25 分)


//最短路  有路径，有救援队的数量，路径条数
#include <bits/stdc++.h> //a

using namespace std;

const int N = 555;
const int inf = 0x3f3f3f3f;
int re[N], res[N];
int leng[N][N], path[N];

vector<int> p;
int length[N], vis[N], ro[N], n, s;
// 对的
void dij() {
    memset(length, inf, sizeof(length));
    memset(path, -1, sizeof(path));
    ro[s] = 1;
    length[s] = 0;
    res[s] = re[s];
    while (true) {
        int v = -1;
        for (int j = 0; j < n; j++) {
//        	可以缩小距离的 好 
            if (!vis[j] && (v == -1 || length[j] < length[v])) {
                v = j;
            }
        }
//        找到最小距离 
//        缩不小了 
        if (v == -1)break;
        vis[v] = 1;
        // 有了v ，哦哦这里是先有v的， prio那边是先有u的
    
        for (int u = 0; u < n; u++) {
            if (vis[u] == 0) {
                // 为什么是u 在前面
                // 为什么这还是对的
                // 所以 这种形式的 就是u在这边 ,prio的就是v在左边
                if (length[u] > length[v] + leng[v][u]) {
                    length[u] = length[v] + leng[v][u];
//                    这是改变道路 
                    ro[u] = ro[v];
                    res[u] = re[u] + res[v];
                    path[u] = v;
                } else if (length[u] == length[v] + leng[v][u]) {
//                	增加道路 
                    ro[u] += ro[v];
                    // 增加救援队
                    if (res[u] < res[v] + re[u]) {
                        res[u] = res[v] + re[u];
                        path[u] = v;
                    }
                }
            }
        }
    }
}

void showPath(int d) {
    int a = d;
    while (a != -1) {
        p.push_back(a);
   
        a = path[a];
    }
    int fir = 1;
    for (int i = p.size() - 1; i >= 0; i--) {
        if (fir) {
            printf("%d", p[i]);
            fir = 0;
        } else {
            printf(" %d", p[i]);
        }
    }
}

int main() {
    printf("dij\n");
    int m, d, i;
//    n点的个数，m条边，s开始，d到
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (i = 0; i < n; i++) {
        scanf("%d", re + i);
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) leng[i][j] = 0;
            else leng[i][j] = inf;
        }
    }
    for (i = 1; i <= m; i++) {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        leng[a][b] = leng[b][a] = len;

    }
    dij();
    printf("%d %d\n", ro[d], res[d]);//路径条数， 救援队最多的数量
    showPath(d);
}
