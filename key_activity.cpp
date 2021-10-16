//
// Created by Lenovo on 2020/11/19.
//

#include<bits/stdc++.h>

using namespace std; // 拓扑排序，

const int N = 111, inf = 0x3f3f3f3f;//但是有些任务必须准时完成 ，关键任务
struct edge {
    int v, u;
} e[555];
int pre[555], g[555][555];
int q[5555], tim[N][N];

int indegree[N], outdegree[N];
int earliest[N], latest[N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = -1;
        }
        indegree[i] = 0;
        outdegree[i] = 0;
        earliest[i] = 0;
        latest[i] = inf;
    }


}

int early_time(int n) {
    int queue[n];
    int front = -1, rear = -1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }
    int cnt = 0;
    while (front < rear) {
        int v = queue[++front];
        cnt++;
//        v 这个点 到其他边的权值

        for (int i = 1; i <= n; i++) {
//            边的权值
//如果是-1 就是没有边
//  i 是其他的边
            if (g[v][i] >= 0) {
                indegree[i]--;
                earliest[i] = max(earliest[i], earliest[v] + g[v][i]);

                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }

            }
        }

    }
    int ans = 0;
    if (cnt != n)ans = -1;
    else {
        ans = earliest[0];
        for (int i = 1; i <= n; i++) {
            if (ans < earliest[i])ans = earliest[i];
        }
//        最大的

    }
    return ans;
}

void late_time(int n, int x) {
    int queue[n];
    int front = -1, rear = -1;
    for (int i = n; i >= 1; i--) {
        if (outdegree[i] == 0) {
            queue[++rear] = i;
            latest[i] = x;
//            这个点 最晚要x个时间 开始
        }
    }
    while (front < rear) {
        int v = queue[++front];
        for (int i = n; i >= 1; i--) {
            if (g[i][v] >= 0) {
                outdegree[i]--;
                latest[i] = min(latest[i], latest[v] - g[i][v]);
                if (outdegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int v, u, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = w;
        indegree[v]++;
        outdegree[u]++;
    }
    int flag = early_time(n);
    if (flag == -1)printf("0\n");
//    flag 关键路径长度，就是最长的路径
//    计算完成整个工程项目需要的最短时间，并输出所有的关键活动。

//    https://blog.csdn.net/qq_36819130/article/details/78551210
//    讲解一下关键路径，关键路径就是最长的一条路径。比如在做一个项目，每条路径都是其中一个工程，
//    所以在正向拓扑的时候选择一个最后结束的点，也就是最后结束的工程
//
//    这工程不结束，这个项目也没有办法结束。然后反向查找，刚才的路径，就是从最后一个结束的点往前找，
//    减去的是路径的权值。如果和每个结点的最后结束的时间想同，那么就是这个结点就是在关键路径上。
    else {
        printf("%d\n", flag);
        late_time(n, flag);
        for (int i = 1; i <= n; i++) {
            if (earliest[i] != latest[i])continue;
            for (int j = n; j >= 1; j--) {
//                如果最晚和最早一样
                if (g[i][j] >= 0 && earliest[j] == latest[j]
                    && (latest[j] - earliest[i] == g[i][j])) {
                    printf("%d->%d\n", i, j);
                }
            }
        }
    }

}