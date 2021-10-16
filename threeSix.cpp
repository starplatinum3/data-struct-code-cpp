//666  怀疑是对的
//        这题目走的是蛇形的
//https://pintia.cn/problem-sets/1314767576917401600/problems/1352143541818150926

//
// Created by Lenovo on 2020/12/31.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 107;
int g[N][N];
int m, n;

//int mov[][2]={{0,1},{0,-1},{1,-1},{1,1},{1,0},{-1,0},{-1,-1},{-1,1}};
//int mov[][2] = {{1,  0},
//                {1,  -1},
//                {0,  -1},
//                {-1, -1},
//                {-1, 0},
//                {-1, 1},
//                {0,  +1},
//                {1,  1}};

int mov[][2] = {{1,  0},

                {0,  -1},

                {-1, 0},

                {0,  +1},
};
//int mov2[][2]={{0,2},{0,-2},{1,-1},{1,1},};
int out[N][N];
int vis[N][N];
//int cnt;

int ok(int i, int j) {
    int cnt = 0;
//    if(i+2>m||j+2>n)return 0;
//    if(i+2<m&&g[i][j]>=6&&g[i+1][j]>=6&&g[i+2][j]>=6)cnt++;
//    if(j+2<n&&g[i][j]>=6&&g[i][j+1]>=6&&g[i][j+2]>=6)cnt++;
//    if(j+2<n&&i+2<n&&g[i][j]>=6&&g[i+1][j+1]>=6&&g[i+2][j+2]>=6)cnt++;
//    if(i-2>=0&&g[i][j]>=6&&g[i-1][j]>=6&&g[i-2][j]>=6)cnt++;
//    if(i-2>=0&&g[i][j]>=6&&g[i-1][j]>=6&&g[i-2][j]>=6)cnt++;
    for (int index = 0; index < 8; index++) {
        int ni = i + mov[index][0];
        int nj = j + mov[index][1];
        int ni2 = i + mov[index][0] * 2;
        int nj2 = j + mov[index][1] * 2;
        if (ni < 0 || ni >= m || ni2 < 0 || ni2 > m)continue;
        if (nj < 0 || nj >= n || nj2 < 0 || nj2 > n)continue;

        if (g[i][j] >= 6 && g[ni][nj] >= 6 && g[ni2][nj2] >= 6) {
            cnt++;
        }
    }
    return cnt;

}

int cnt = 0;

void search(int i, int j, int step, int &cnt) {
    if (step >= 2) {
//        cnt++;
        cnt++;

        return;
    }
//    vis[i][j] = 1;
//    if (i >= 0 && j >= 0 && i < m && j < n && g[i][j] >= 6) {
//    if (i >= 0 && j >= 0 && i < m && j < n ) {
//        cnt++;
//    }
//    vis[i][j]=1;
    for (int index = 0; index < 4; index++) {
        int ni = i + mov[index][0];
        int nj = j + mov[index][1];

        if (ni < 0 || ni > m)continue;
        if (nj < 0 || nj > n)continue;

        if (vis[ni][nj] == 0 && g[ni][nj] >= 6) {
//            int ni2=i + mov[index][0]*2;
//            int nj2=j + mov[index][1]*2;
            vis[ni][nj] = 1;
            search(ni, nj, step + 1, cnt);
            vis[ni][nj] = 0;
        }
    }
}

void search(int i, int j, int step) {
    if (step >= 2) {
//        cnt++;
        cnt++;

        return;
    }
//    vis[i][j] = 1;
//    if (i >= 0 && j >= 0 && i < m && j < n && g[i][j] >= 6) {
//    if (i >= 0 && j >= 0 && i < m && j < n ) {
//        cnt++;
//    }
//    vis[i][j]=1;
    for (int index = 0; index < 4; index++) {
        int ni = i + mov[index][0];
        int nj = j + mov[index][1];
//        上下左右 试着走一步
//碰到墙了 不要
        if (ni < 0 || ni > m)continue;
        if (nj < 0 || nj > n)continue;

        if (vis[ni][nj] == 0 && g[ni][nj] >= 6) {
//            int ni2=i + mov[index][0]*2;
//            int nj2=j + mov[index][1]*2;
            vis[ni][nj] = 1;
            search(ni, nj, step + 1);
            vis[ni][nj] = 0;
        }
    }
}

int main() {
//左右上下 不能斜着走的
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
//    int cnt=0;
    int totCnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
//            out[i][j] = ok(i, j);


//            int cnt = 0;
            cnt = 0;
            if (g[i][j] >= 6) {
                vis[i][j] = 1;
//                search(i, j, 0, cnt);
                search(i, j, 0);
                vis[i][j] = 0;
            }

            out[i][j] = cnt;
//            cnt += out[i][j];
            totCnt += cnt;
        }
    }
    for (int i = 0; i < m; i++) {
        int fir = 1;
        for (int j = 0; j < n; j++) {
            if (fir) {
                fir = 0;
                printf("%d", out[i][j]);
            } else printf(" %d", out[i][j]);

//            out[i][j]=ok(i,j);
//            cnt+=out[i][j];
        }
        printf("\n");
    }
    printf("%d\n", totCnt);

}