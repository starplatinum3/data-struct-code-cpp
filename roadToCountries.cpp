//
// Created by Lenovo on 2020/11/5.
//
//7-1 公路村村通 (30分)
//https://pintia.cn/problem-sets/1323860289121378304/problems/1323865688067227648
#include<stdio.h>
#include <iostream>
using namespace std;

#include <algorithm>
struct Edge
{
    int u,v,w;
}edge[200005];
int fa[5050],n,m,ans,eu,ev,cnt;
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

int find(int x)
{
    while(x!=fa[x])x=fa[x]=fa[fa[x]];
    return x;
}

void kruskal()
{
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;i++)
    {
        eu=find(edge[i].u),ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        ans+=edge[i].w;//生成树得边权之和
        fa[ev]=eu;
        if(++cnt==n-1)break;//==n-1会退出 因为最多这么多边
    }


}
int  mainKruskal()
{
    cin>>n>>m;
//    镇数目正整数N（≤1000）和候选道路数目M（≤3N）
    for(int i=1;i<=n;i++)//n是点的个数
    {
        fa[i]=i;
    }
    for(int i=0;i<m;i++)//m是边得个数
    {
        cin>>   edge[i].u>>edge[i].v>>edge[i].w;//左边 右边 权重
//        分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。
    }
    kruskal();
    printf("%d",ans);
    return 0;
}

int main(){
     mainKruskal();
}