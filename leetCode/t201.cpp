
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
    vector<int> visited;
    // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    vector<int> result;
    // 判断有向图中是否有环
    bool valid = true;

public:
    void dfs(int u)
    {
        // 将节点标记为「搜索中」
        visited[u] = 1;
        // 搜索其相邻节点
        // 只要发现有环，立刻停止搜索
        for (int v : edges[u])
        {
            // 如果「未搜索」那么搜索相邻节点
            if (visited[v] == 0)
            {
                dfs(v);
                // 有环  是没有效的
                if (!valid)
                {
                    return;
                }
            }
            // 如果「搜索中」说明找到了环
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        // 将节点标记为「已完成」
        visited[u] = 2;
        // 将节点入栈
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && valid; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        if (!valid)
        {
            return {};
        }
        // 如果没有环，那么就有拓扑排序
        // 注意下标 0 为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/course-schedule-ii/solution/ke-cheng-biao-ii-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// int main(int argc, char* argv[]){

// }

int main()
{
    Solution solution = Solution();
    // int testNum=14;
    // vector<vector<int>> persons();
    vector<vector<int>> persons;
    // persons.push_back({1,0});
    // vector<int>arr();
    // vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(0);
    // persons.push_back(arr);
    // 这个也可以的
     persons.push_back(vector<int>{1,0});
    vector<int> res = solution.findOrder(2, persons);
    // bool res=solution.isUgly(6);
    //    printf(" %d ",res);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}