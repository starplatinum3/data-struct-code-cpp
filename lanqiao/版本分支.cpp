#include <iostream>
#include <vector>//邻接数组
using namespace std;
 
const int N=100001;
vector<int> v[N];
int n,q,t[N],f[N],ts=0;
void dfs(int x)
{
    ts++;//时间戳
    t[x]=ts;//开始时间戳
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        dfs(y);
    }
    ts++;
    f[x]=ts;//结束时间戳
}
int main()
{
    int m,l,x,y;
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        cin>>m>>l;
        v[m].push_back(l);
    }
    dfs(1);
    while(q--)
    {
        cin>>x>>y;
    // 开始时间戳小 结束时间戳 大,是祖先
        if(t[x]<=t[y]&&f[x]>=f[y]){
            printf("t[x] %d,x:%d, t[y] :%d, y: %d\n",t[x],x,t[y],y);
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

// https://blog.csdn.net/wanghuiqiang1/article/details/87646001