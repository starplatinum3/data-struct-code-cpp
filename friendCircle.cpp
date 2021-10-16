//
// Created by Lenovo on 2020/10/31.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <map>
#include <algorithm>
namespace friendCircle{

using namespace std;
int n,m;
int father[30005];
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    else
        return father[x];
}
int ans[30005];
int mainFriendCircle()
{
    scanf("%d%d",&n,&m);
//    分别代表学校的学生总数和俱乐部的个数。
    int x;
    int y;
    for(int i=1;i<=n;i++)
        father[i]=i;
//    俱乐部的个数
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
//        第i个俱乐部的人数Mi
        int yy=0;
        for(int j=1;j<=x;j++)
        {
            scanf("%d",&y);
//            每个学生的编号
//第一次进来肯定是0的
            if(yy!=0)
            {
//                除了第一个以外的人，都要和第一个人来一次合并
                int fx=find(yy);
                int fy=find(y);
                father[fx]=fy;
            }
            else
                yy=y;
//            yy是一个俱乐部里面第一个学生的编号
        }
    }
    for(int i=1;i<=n;i++)
    {
        int fa=find(i);
//        每个人的编号去找一找他的爸爸
        ans[fa]++;
    }
    sort(ans+1,ans+n+1);
    printf("%d\n",ans[n]);
    return 0;
}

//https://blog.csdn.net/Dacc123/article/details/61619854


}