//
// Created by Lenovo on 2020/12/31.
//
//https://blog.csdn.net/zp1455604302/article/details/103657600
#include<iostream>
#include<algorithm>

using namespace std;
int n, t, a[1005], vis[1005], ans, cnt, shouldBlank;

void dfs(int fromIndex) {
    if (ans < t) {
        for (int i = fromIndex; i < n; i++) {
            if (!vis[i]) {
//                如果这个数字还没有选过，那我选一下，把他加在ans上面
                vis[i] = 1;
                ans += a[i];
                dfs(i + 1);
//                往后面去选数字
//消除影响
                vis[i] = 0;
                ans -= a[i];
            }
        }
    }
//   我之前选的使得 零钱合适了，把选的那些打印一下

    else if (ans == t) {
        shouldBlank = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                if (shouldBlank) {
                    putchar(' ');
                }
                shouldBlank = 1;
                cout << a[i];
            }
        }
        printf("\n");
        cnt++;
//        增加了一种可能性
    }
}

//收银员现有 n 张面值分别为 v1,v2,…,v​n 的纸币。若找零金额为 m，则一共有多少种找零方法？
//
//注：0<n≤1000，0<v1,v2,…,vn≤10000，0<m≤10000
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &t);
//    找零金额
    dfs(0);
//    从0 下标开始选
    if (!cnt)
        printf("None\n");

    return 0;
}


void printArr() {
    int fir = 1;

    for (int i = 0; i < n; i++) {
        if (fir) {
            printf("%d", a[i]);
//                putchar(' ');
            fir = 0;
        } else {
            printf(" %d", a[i]);
        }
    }

    putchar('\n');
}
