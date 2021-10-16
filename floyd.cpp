//
// Created by Lenovo on 2020/11/12.
//
//07-图4 哈利·波特的考试 (25分)
#include <bits/stdc++.h>

using namespace std;
int leng[111][111];
int n, m;
const int inf = 0x3f3f3f3f;
int ma[111];

int floyd() {
    int i, j, k;
    //int d[105];

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
//                这里好像必须这样写
//                如果i->k->j 有一条比之前求出来的i->j的更短的边，就变
                if (leng[i][k] + leng[k][j] < leng[i][j]) {
                    //if(leng[k][i]==inf||leng[i][j]==inf)continue;
                    leng[i][j] = leng[i][k] + leng[k][j];
                    //    printf("k==%d,j==%d,leng[k[j==%d\n",k,j,leng[k][j]);
                }

    return 0;
}

int main() {

    cin >> n >> m;
    int i, v, num, len, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            leng[i][j] = inf;
    for (i = 0; i < m; i++) {
        cin >> num >> v >> len;
        leng[num][v] = len;
        leng[v][num] = len;
    }

    floyd();
    int no = 0;
//    有一个变形是不行的，那就是no
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (leng[i][j] == inf)
                no = 1;

//    输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，
//    中间以空格分隔。如果只带1只动物是不可能完成所有变形要求的，则输出0。如果有若干只动物都可以备选，则输出编号最小的那只。

//
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (ma[i] < leng[i][j] && i != j && leng[i][j] != inf)
                ma[i] = leng[i][j];
//            最长的变形魔咒的长度
        }
    }

//   for(i=1;i<=n;i++)printf("ma[i=%d,i==%d\n",ma[i],i);


    int mi = ma[n];
    int ind = n;
//    则输出编号最小的那只。
    for (i = n; i >= 1; i--)
        if (mi >= ma[i]) {
            mi = ma[i];
            ind = i;
        }
    if (no)printf("0\n");
    else printf("%d %d\n", ind, ma[ind]);
}