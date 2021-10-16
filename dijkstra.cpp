//
// Created by Lenovo on 2020/11/14.
//

#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int MAX = 2505;

int n,m,s,t;

int map[MAX][MAX];

int d[MAX];

bool vis[MAX];

void Dijkstra(){

//    这里要初始化吗 有些好像不写的
    for(int i=1;i<=n;i++){

        d[i] = map[s][i];
    }
// 这里的vis 也不知道需不需要
    vis[s] = true;
    d[s] = 0;

    for(int i=1;i<n;i++){

        int minx = 0x7f7f7f7f;
        int pos;

        for(int j=1;j<=n;j++){

            if(!vis[j] && d[j] < minx){

                minx = d[j];
                pos = j;
            }
        }

        if(minx == 0x7f7f7f7f)
            break;

        vis[pos] = true;

        for(int j=1;j<=n;j++){

            d[j] = min(d[j],d[pos]+map[pos][j]);
        }
    }

}

int main(){

    cin>>n>>m>>s>>t;

    memset(vis,false,sizeof(vis));
    memset(map,0x7f7f7f7f,sizeof(map));

    for(int i=0;i<m;i++){

        int s,t,w;
        cin>>s>>t>>w;
//        无向图，
        map[s][t]=map[t][s]=w;
    }

    Dijkstra();

    cout<<d[t]<<endl;


    return 0;
}

//https://blog.csdn.net/qq_41700374/article/details/100554100
//
//7-1 Dijkstra算法（模板）
