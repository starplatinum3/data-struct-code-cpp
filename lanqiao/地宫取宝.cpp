#include <stdio.h>
#include <string.h>
#define N 1000000007
int n,m,k;
int map[50][50];
int vis[50][50][15][15];//vis数组中记录的是状态：xy代表坐标 拥有宝物数量 拥有宝物的最大值(这4个可以详尽唯一的描述每一种可能)
//  如   vis[3][4][5][6]=7 即当在map[3][4]且身上有5件宝物 宝物的最大值是6 到达终点有7种路径

int dfs(int x,int y,int num,int max)//当前位置   拥有宝物的数量 拥有的宝物的最大值
{
    // -1 没有访问
    if (vis[x][y][num][max+1]!=-1)//因为宝物的价值有可能为0，所以定义max时用最小值-1 。
    // 但这就导致无法作为下标使用，所以我们用max+1代表下标。实际上如果测试数据中宝物价值不可能为0，
    // 这时将所有的max+1中的1去掉也是可以的。
    {
        return vis[x][y][num][max+1];
    }//记忆化的记忆就指的是上面
    if(x==n&&y==m)
    {
        if(num==k)return vis[x][y][num][max+1]=1;//满足条件 当前点到目标有1种方案
        // 拥有的宝物的最大值<map[x][y]地图上有的 可以拿走 然后出去
        // 格子上的大
        else if(num==k-1&&max<map[x][y])return vis[x][y][num][max+1]=1;//同样满足条件 当前点到目标有1种方案
        else return vis[x][y][num][max+1]=0;//不满足条件 当前点到目标有0种方案
    }
    long long s=0;
    // row ++ 就是 向下
    if(x+1<=n)//可以向下走
    {
        // ，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小
        if (max<map[x][y])   //可以取走当前宝物
        {
            s+=dfs(x+1,y,num+1,map[x][y]);
            s%=N; //每次都取余，这样可以避免是s值过大越界
        }
        // 不用 else吗 因为可以选择拿或者不拿 好像不是else 的关系
        // 就算可以拿 也可以不拿
        s+=dfs(x+1,y,num,max);//未取走当前宝物
        s%=N;
    }
    if(y+1<=m)//可以向右走
    {
        if (max<map[x][y])
        {
            s+=dfs(x,y+1,num+1,map[x][y]);
            s%=N;
        }
        s+=dfs(x,y+1,num,max);
        s%=N;
        // s 方案数
    }
    return vis[x][y][num][max+1]=s%N;;
}
int main(int argc, char const *argv[])
{
    // k件宝贝
    scanf("%d%d%d",&n,&m,&k);

    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }//初始地宫
    memset(vis,-1,sizeof(vis));
    dfs(1,1,0,-1);
    //  拿了0个
    printf("%d",vis[1][1][0][0]);
    // 从 1 1 开始
    // 如 vis[1][1][0][0] 即当在map1 1且身上有0件宝物 宝物的最大值是0 到达终点有？种路径
    return 0;
}
