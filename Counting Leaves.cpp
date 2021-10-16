//
// Created by Lenovo on 2021/2/25.
//

#include<bits/stdc++.h>
using namespace std;

int n;
int m;
const int   MAX_N=107;
vector<int>g[MAX_N];
bool  vis[MAX_N];
int root;
void bfs(){

    for(auto v:g[u]){

    }
}
int main(){
    while (true){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        scanf("%d",&m);
        for (int i = 0; i < m; ++i) {
            int id,k;
            scanf("%d %d",&id,&k);
            root=id;
            for (int j = 0; j <k ; ++j) {
                int u;
                scanf("%d",&u);
                g[id].emplace_back(u);
            }
        }
    }


}
