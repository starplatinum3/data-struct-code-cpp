#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int a[maxn];
int sum[maxn];
int n,maxWeight;
int ans=maxn;
// ，一次最多可以拿起重量为 \mathit mm 的东西。
// 之后，牛牛终于洗完了 \mathit nn 件衣服，但是，
// https://www.nowcoder.com/questionTerminal/ef53bb4f023d4abaa7ff8d09c009fedf?answerType=1&f=discussion
void dfs(int now,int usedBukect)//u当前遍历到第几只猫，k已经用了几个桶
{
    if(usedBukect>=ans)//如果目前用的桶已经超过当下的最优解，已经没有必要搜索下去了
        return;
    if(now==n)
    {
        ans=usedBukect;//不用是ans=min(ans,usedBukect)，因为前面k>=ans,已经返回了
        return;
    }
    for(int i=0;i<usedBukect;i++)
    {
        if(a[now]+sum[i]<=maxWeight)//如果在第i个放下第now件衣服没有超过m，可以继续遍历下去
        {
            sum[i]+=a[now];
            dfs(now+1,usedBukect);
            sum[i]-=a[now];//回溯
        }
    }
    sum[usedBukect]=a[now];//新建一个桶
    dfs(now+1,usedBukect+1);
    sum[usedBukect]=0;//回溯
}
int main()
{
 cin>>n>>maxWeight;
 for(int i=0;i<n;i++)
    cin>>a[i];
 sort(a,a+n);
 reverse(a,a+n);//大到小排序
 dfs(0,0);
 cout<<ans<<endl;
    return 0;
}
