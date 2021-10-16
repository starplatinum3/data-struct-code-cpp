//
// Created by Lenovo on 2020/11/26.
//
#include <stdio.h>
#include <queue>

void midNum() {
//    第一行给出序列的公共长度N（0<N≤100000
    using namespace std;
    int n;
    scanf("%d", &n);
    priority_queue<int> q;
    for (int j = 0; j < 2; j++) {

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            q.emplace(x);
        }
    }
//    A (N−1)/2
//    ​​(2n-1)/2= n-1/2 =n-0=n;
    for(int i=0;i<n;i++){
        q.pop();
    }
    printf("%d\n",q.top());

}

void midNum() {
//    第一行给出序列的公共长度N（0<N≤100000
    using namespace std;
    int n;
    scanf("%d", &n);
    priority_queue<int> q;
    for (int j = 0; j < 2; j++) {

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            q.emplace(x);
        }
    }

//    5
//    1 3 5 7 9
//    2 3 4 5 6
//   1 2 3 3 4 5 5 6 7 9
//    (5-1)/2==2
    for(int i=0;i<n;i++){
        q.pop();
    }
    printf("%d\n",q.top());

}
