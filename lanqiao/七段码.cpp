//
// Created by Lenovo on 2021/2/10.
//
//https://blog.csdn.net/qq_45530271/article/details/109189978
#include<bits/stdc++.h>
using namespace std;
const int N=10;
int use[N],ans,e[N][N],fa[N];
void init(){
    //连边建图
    //a b c d e f g
    //1 2 3 4 5 6 7
    e[1][2]=e[1][6]=1;
    e[2][1]=e[2][7]=e[2][3]=1;
    e[3][2]=e[3][4]=e[3][7]=1;
    e[4][3]=e[4][5]=1;
    e[5][4]=e[5][6]=e[5][7]=1;
    e[6][1]=e[6][5]=e[6][7]=1;
}
int find(int u){if(fa[u]==u)return u;fa[u]=find(fa[u]);return fa[u];}//并查集
void dfs(int d){
    if(d>7){
        /* 并查集判联通 */
        for(int i=1;i<=7;i++)fa[i]=i;
        for(int i=1;i<=7;i++)
            for(int j=1;j<=7;j++)
                if(e[i][j]&&use[i]&&use[j]){
                    int fx=find(i),fy=find(j);
                    if(fx!=fy){
                        fa[fx]=fy;
                    }
                }
        int k=0;
        for(int i=1;i<=7;i++)if(use[i]&&fa[i]==i)k++;
//        如果这个电灯点亮了 并且
// 并查集只有一个 fa[i]==i的话 说明都是联通的
        if(k==1)ans++;
        return;
    }
    use[d]=1;
    dfs(d+1);
//    去选择下一个
//    这个灯泡是选择 打开还是关闭
//    连了一个
    use[d]=0;
    dfs(d+1);
}
int main(){
    init();
    dfs(1);
    cout<<ans;
}
