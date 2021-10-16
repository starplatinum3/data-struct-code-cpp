/**
题意: 给定N, K, P; 将N表示成K个正整数的P次方的和，如果有多中方案，那么选择n1 + .. nk的最大的方案；
如果还有多种方案，选择序列的字典序最大的方案；
**/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, k, p;
int maxFacSum = -INF;//最大底数之和
vector<int> fac, ans, temp;//最优底数序列和临时序列
/**
求n^p
**/
int power(int x) {
    int ans = 1;
//    p 是2 的话 就是
//	tmp: 0
//tmp: 1
//tmp: 4
//tmp: 9
//tmp: 16
//tmp: 25
//tmp: 36
//tmp: 49
//tmp: 64
//tmp: 81
//tmp: 100
//tmp: 121
//tmp: 144   大 最好选这个 
    for (int i = 0; i < p; i++) {
        ans *= x;
    }
    return ans;
}
/**
初始化fac数组注意0
**/
void init() {
    int i = 0, tmp = 0;
    while (tmp <= n) {
        fac.push_back(tmp);
        cout<<"tmp: "<<tmp<<", i : "<<i<<"\n";
        tmp = power(++i);
    }
}
/**
DFS函数
index: 当前访问；
nowK:当前选中个数
sum:当前的数的和
facSum:当前的底数的和, n1 + n2 +... + nk;
**/
 
void DFS(int index, int nowK, int sum, int facSum) {
    if (sum > n || nowK > k) return;
    if (sum == n && nowK == k) {
        if (facSum > maxFacSum) {
            maxFacSum = facSum;
            ans = temp;
        }
        return;
    }
    if (index - 1 >= 0) {//fac[0]不需要
        //选index
        // 因为是从index 大的开始选， 
        // 上面有这个 facSum > maxFacSum 更新， 就是选了大的之后尝试小的， 小的要更加
        // 优秀才是选择小的
        temp.push_back(index);
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        //不选index
        // 放前面是错的
        temp.pop_back();
        DFS(index - 1, nowK, sum, facSum);
    }
}


void DFS(int index, int nowK, int sum, int facSum) {
    if (sum > n || nowK > k) return;
    if (sum == n && nowK == k) {
        if (facSum >= maxFacSum) {
            maxFacSum = facSum;
            ans = temp;
        }
        return;
    }
    if (index - 1 >= 0) {//fac[0]不需要
        //选index
        // 因为是从index 大的开始选， 
        // 上面有这个 facSum > maxFacSum 更新， 就是选了大的之后尝试小的， 小的要更加
        // 优秀才是选择小的
        // 但是也可以这样  先选择小的， 尝试了小的之后， 后面如果大的和小的同等
        // 优秀 （facSum >= maxFacSum） 也是要更新的
        DFS(index - 1, nowK, sum, facSum);

        temp.push_back(index);
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        //不选index
        // 放前面是错的
        temp.pop_back();
        
    }
}




//https://www.baidu.com/link?url=M-FULpWyMeSYEB6EKyG3BtNT-l4jI6VZc_4ZWbCgWVRnPzFTU6Qw_MGHxkn_qXtFyN3M1EGiUYzs9zmH2zgDcIjnkfajjaU0-PJ-u7OhgRi&wd=&eqid=c883f1060012a62f000000056044e6d0
int main() {
    cin >> n >> k >> p;
//    n  sum 
    init();
    DFS(fac.size() - 1, 0, 0, 0);
    if (maxFacSum == -INF) cout << "Impossible" << endl;
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size(); i++) {
            printf(" + %d^%d", ans[i], p);
        }
        printf("\n");
    }
	return 0;
}
