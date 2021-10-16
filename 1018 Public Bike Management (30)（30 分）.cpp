//1018 Public Bike Management (30)（30 分）

//https://blog.csdn.net/CV_Jason/article/details/81385228

/*
** @Brief:No.1018 of PAT advanced level.
** @Author:Jason.Lee
** @Date:2018-8-03
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 设置最大值的上限 
const int inf = 99999999;
int cmax, n, sp, m;
// minNeed 是最小需求，minBack是最小 
int minNeed = inf, minBack = inf;
// 数组下标作为顶点标记，e存储边信息，dis更新距离信息，weight记录每个顶点的权重 
int e[510][510], dis[510], weight[510];
// visit 记录是否访问过 
bool visit[510];

vector<int> pre[510];// 每个顶点向下一个顶点，可能存在多个选择 
vector<int> path, temppath;

//深度优先遍历，输入顶点V，开始对其进行dfs搜索
//注意搜索方向是从sp顶点到0顶点，且搜索路径是已经被Dijkstra算法优化过的路径 

//　每个自行车站可以看做一个顶点，每条路可以看做带权路径，注意，顶点的状态有三个，
//不需要执行任何操作的perfect condition，目标修复顶点 problem condition，
//以及介于两者之间需要操作的顶点。在计算完最短路径之后，从目标顶点返回到0顶点，
//计算需要补送的自行车数量（need），以及需要带走的自行车的数量（back）。
//注意，出了proble condition顶点之外，其余顶点的自行车数量，有可能是多的，就是最后还要带回到0顶点一些自行车。
//————————————————
//版权声明：本文为CSDN博主「大山喵」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/CV_Jason/article/details/81385228
void dfs(int v) {
    // 深度优先路过的顶点，存入到temppath 
    temppath.push_back(v);
    // 当到达顶点0的时候，开始计算 
    if(v == 0) {
        int need = 0, back = 0;
//        后面的顶点 是相近 的 
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            // 该顶点的自行车处于多的状态 
            if(weight[id] > 0) {
                //
                back += weight[id];
            } else {
                // 该顶点的自行车处于少或者完美状态 
//                (0 - weight[id]) 缺少这些 成为完美 
                if(back > (0 - weight[id])) {
                    // 如果back中是足够的，先从back中扣出 
//                    就是 back += 一个负数 
                    back += weight[id];
//                    带过来的东西 放在这里了 
                } else {
//                	不够放在这里 
                    // 如果back不够，那么需要从need中借 
                    need += ((0 - weight[id]) - back);
//                    缺多少 need 的增多了 
                    back = 0;
                }
            }
        }
        //计算最小的需求 
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
            //计算最小需求中带回来最少的 
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        // 顶点在dfs访问结束后弹出 
        temppath.pop_back();
        return ;
    }

    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
//        终点往回走 
    // 该顶点在dfs访问结束后弹出 
    temppath.pop_back();
}
int main() {
    // 初始化二维数组e 
    fill(e[0], e[0] + 510 * 510, inf);
    // 初始化数组dis  
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        // 直接计算得到，相对于perfect状态的需求 
        weight[i] = weight[i] - cmax / 2;
//        本来 0个 就是 -5  差了5个 
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    // 顶点0到自身的距离自然是0 
    dis[0] = 0;
    // 双重for循环遍历整张图，Dijkstra算法 
    // 外层循环表示遍历0~N个顶点 
//    外面没有vis 
    for(int i = 0; i <= n; i++) {
        // 选出距离顶点0距离最小的顶点u
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        // 该循环的作用是通过e来更新u顶点与其他顶点的最小路径 
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                // 更新u顶点到v顶点的更小值 
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v] == dis[u] + e[u][v]) {
                    // u v 之间可能存在多个最短路径 
                    pre[v].push_back(u);
//                    另外一条路 
                }
            }
        }
    }
    // 对problem station 进行深度优先搜索，以选取多个路径当中最符合条件的一个 
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
} 
