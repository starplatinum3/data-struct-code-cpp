#include <iostream>
#include<bits/stdc++.h>
//https://blog.csdn.net/weixin_43637016/article/details/104681069
using namespace std;
int n, k, ans;
double sum = 0;
//int sum = 0;
const int MAX_N = 120;
double a[333]{1570.56 ,
              1568.64 ,
              1435.34 ,
              1693.9 ,
              1904.74 ,
              1847.1 ,
              700 ,
              1564.8 ,
              1351.92 ,
              1476.62 ,
              1473.29 ,
              1438.78 ,
              1606.08 ,
              1358.4 ,
              1200 ,
              700 ,
              1512 ,
              2206.65 ,
              1159.2 ,
              1769.58 ,
              1190.28 ,
              1412.32 ,
              1652.52 ,
              2693.1 ,
              2037.45 ,
              2191.31 ,
              0 ,
              0 ,
              2497.11 ,
              0 ,
              0 ,
              2316.63 ,
              1677.61 ,
              785.29 ,
              1817.27 ,
              556.6 ,
              0 ,
              2177.04 ,
              1401.4 ,
              2016.3 ,
              1773.78 ,
              262.74 ,
              0 ,
              2055.78 ,
              1843.45 ,
              1765.32 ,
              1297.66 ,
              1771.44 ,
              2608.5 ,
              1436.4 ,
              2719.89 ,
              1372.14 ,
              1521.6 ,
              1868.25 ,
              2325.09 ,
              1239.26 ,
              1939.23 ,
              1401.88 ,
              633.09 ,
              0 ,
              1501.76 ,
              900 ,
              1391.13 ,
              0 ,
              1711.74 ,
              0 ,
              1419.68 ,
              800 ,
              1698.24 ,
              0 ,
              2089.62 ,
              2265.48 ,
              2358.93 ,
              2231.46 ,
              1599.62 ,
              1639.55 ,
              1771.2 ,
              2301.12 ,
              1470.72 ,
              1577.28 ,
              1182.17 ,
              0 ,
              2428.02 ,
              1551.36 ,
              1373.35 ,
              0 ,
              1801.69 ,
              1160.43 ,
              0 ,
              3466.32 ,
              2896.32 ,
              2566.34 ,
              531.26 ,
              650 ,
              2188.32 ,
              1772.37 ,
              875.61 ,
              0 ,
              2054.37 ,
              2134.74 ,
              1358.63 ,
              2363.48 ,
              0 ,
              1733.76 ,
              2281.86 ,
              1714.02 ,
              1369.72 ,
              179.27 ,
              2186.1 ,
              665.21 ,
              1840.41 ,
              0 ,
              0 ,
              1637.21 ,
              0 ,
              153.72 ,
              1928.88 ,

};
int intArr[333];

#include "util/printUtilNotClass.h"
bool xuan[333];
vector<int>selIndexArr;
void printXuan() {
    printf("======\n");
    printf("xuan \n");
    selIndexArr.clear();
    vector<int>selIndexArrNot0;
    double xuanSum=0;
    for (int i = 0; i < MAX_N; i++) {
        if (xuan[i]) {
            xuanSum+=a[i];
//            printf("[%d] %d, ", i, intArr[i]);
            printf("[%d] %.2lf, ", i, a[i]);
//            printf("[%d] %.2lf\n",i,a[i]);
//        selIndexArr.push_back(i);
        if(a[i]!=0){
            selIndexArrNot0.emplace_back(i);
        }

        }
    }
    putchar('\n');
    printf("index\n");
//    printVector(selIndexArr);
    printVector(selIndexArrNot0);
//    printf("Ñ¡ÔñµÄsum : %.2f\n",xuanSum);
    printf("sel sum : %.2f\n",xuanSum);
}

//(double s,
void dfs(double s, int cnt, int pos) {
    if (s > sum || cnt > k) {
        return;
    }

//    if (s > sum || cnt > k) {
//        return;
//    }
//
//    s == sum
//    if (s == sum && cnt == k)
    if (abs(s - sum) <= 1) {
        ans++;
        printf("sum: %.2lf\n", s);
//        printf("sum: %d\n",s);
        printXuan();

    }
//    for (int i = pos; i < n; i++) {
    for (int i = pos; i < MAX_N; i++) {
        if (!xuan[i]) {
            xuan[i] = 1;
//            if(intArr[i]==0)continue;
//            dfs(s + intArr[i], cnt + 1, i + 1);
            dfs(s + a[i], cnt + 1, i + 1);
            xuan[i] = 0;
        }
    }
}

void makeIntArr() {
    for (int i = 0; i < MAX_N; ++i) {
        intArr[i] = (int) a[i];
    }
}

void setFalse() {
    for (int i = 0; i < MAX_N; i++) {
        xuan[i] = false;
    }

}

struct  Node{
    int w,id;

    bool operator<(const Node &rhs) const {
        return w < rhs.w;
    }

    bool operator>(const Node &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Node &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Node &rhs) const {
        return !(*this < rhs);
    }
};
int main() {
//    string s="1110";
//	int intNum= stoi(s,2);
//		int intNum= stoi(s);
//    int intNum= atoi(s,2);
//    printf("intNum : %d\n",intNum);


//    n = 30;
//    k = 17;
//    sum = 24040.00;
    sum = 11000.00;
//    for (int i = 0; i < 30; i++) {
//        a[i] = i + 1;
//    }
    ans = 0;
//    makeIntArr();
//    for (k = 100; k <= 120; k++) {
//        printf("test k : %d\n", k);
//        setFalse();
//        dfs(0, 0, 0);
////    printXuan();
//    }
//
    k = 111;
    printf("test k : %d\n", k);
    setFalse();
//    dfs(0, 0, 0);
    dfs(0, 0, 15);

//    cout << ans << endl;
    return 0;
}
