//
// Created by Lenovo on 2020/12/23.
//

#include <stdio.h>
#include <iostream>
using  namespace std;
#define ElementType int
#define MAXN 100
int graph[1111][1111]={0};
int adjNum[1111]={0};
int father[1111] = {0};
int find(int index){
    if(index == father[index]) return index;
    else return  father[index] = find(father[index]);
}
int Iterative_find(int index){
    int a;
    a = index;
    while(index != father[index]) index = father[index];
    while(a!=father[a]){
        int z = a;
        a = father[a];
        father[z] = index;
    }
    return index;
}
void Union(int a,int b){
    int fa = Iterative_find(a);
    int fb = Iterative_find(b);
    if(fa!=fb) father[fa] = fb;
}
int main(void){
    int n,m;
    cin >>n >>m;
    for (int i = 1; i <= n; ++i)
        father[i] = i;
    for(int i =0; i< m; i++){
        int from , to;
        cin >> from >> to;
        Union(from,to);
        adjNum[from]++;
        adjNum[to]++;
        //    读图的时候就保存和每个点相连的点有多少个
        graph[to][from] = graph[from][to] = 1;
        // 无向图，正反都要表示联通
    }
    int oddPoint=0;
    // 如果连接的点数是奇数的话，oddPoint++
    for(int i=1; i<n+1; i++)if(adjNum[i]%2!=0)oddPoint++;
    int root=0;
    for(int i=1; i<=n; i++) if(father[i]==i) root++;
    int isConnect = root==1? 1:0;
    //   如果一个点和其他点相连是奇数，这样的点是0个或者2个的话，是可以一笔画的。
    //   还要判断一下图是不是联通，可以用并查集判断，如果所有点的爹都是同一个的话，那就是联通的
    if(isConnect && (oddPoint==0||oddPoint==2)) printf("Y");
    else printf("N");
}