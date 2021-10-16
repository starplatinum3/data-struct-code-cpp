//
// Created by Lenovo on 2020/12/6.
//
const int maxn = 1e5 + 7;
int f[maxn];
int howMany[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
        howMany[i] = 1;
    }
}

int find(int x) {
    if (x == f[x])return x;
    return f[x] = find(f[x]);
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
//        fy  is dad
//fy more persons ,he is dad
        if (howMany[fx] < howMany[fy]) {
            f[fx] = fy;
            howMany[fy]+= howMany[fx];
            howMany[fx]=0;
        } else {
            f[fy] = fx;
            howMany[fx]+= howMany[fy];
            howMany[fy]=0;
        }

    }
}

int getCountOfBiggestSet() {
    int fatherHaveChildren[maxn];
    for(int i=0;i<maxn;i++){
        int fatherNum=find(i);
        fatherHaveChildren[fatherNum]++;
    }
    return  maxInArr(fatherHaveChildren);
}

int getCountOfSets(int n) {
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            cnt++;
        }
    }
    return cnt;
}
using namespace std;

#include<vector>

int disjointSetTest() {
    vector<int> personsA;
    vector<int> personsB;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            unite(i, j);
        }
    }
}