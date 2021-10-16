//1018 Public Bike Management (30)��30 �֣�

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
// �������ֵ������ 
const int inf = 99999999;
int cmax, n, sp, m;
// minNeed ����С����minBack����С 
int minNeed = inf, minBack = inf;
// �����±���Ϊ�����ǣ�e�洢����Ϣ��dis���¾�����Ϣ��weight��¼ÿ�������Ȩ�� 
int e[510][510], dis[510], weight[510];
// visit ��¼�Ƿ���ʹ� 
bool visit[510];

vector<int> pre[510];// ÿ����������һ�����㣬���ܴ��ڶ��ѡ�� 
vector<int> path, temppath;

//������ȱ��������붥��V����ʼ�������dfs����
//ע�����������Ǵ�sp���㵽0���㣬������·�����Ѿ���Dijkstra�㷨�Ż�����·�� 

//��ÿ�����г�վ���Կ���һ�����㣬ÿ��·���Կ�����Ȩ·����ע�⣬�����״̬��������
//����Ҫִ���κβ�����perfect condition��Ŀ���޸����� problem condition��
//�Լ���������֮����Ҫ�����Ķ��㡣�ڼ��������·��֮�󣬴�Ŀ�궥�㷵�ص�0���㣬
//������Ҫ���͵����г�������need�����Լ���Ҫ���ߵ����г���������back����
//ע�⣬����proble condition����֮�⣬���ඥ������г��������п����Ƕ�ģ��������Ҫ���ص�0����һЩ���г���
//��������������������������������
//��Ȩ����������ΪCSDN��������ɽ������ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/CV_Jason/article/details/81385228
void dfs(int v) {
    // �������·���Ķ��㣬���뵽temppath 
    temppath.push_back(v);
    // �����ﶥ��0��ʱ�򣬿�ʼ���� 
    if(v == 0) {
        int need = 0, back = 0;
//        ����Ķ��� ����� �� 
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            // �ö�������г����ڶ��״̬ 
            if(weight[id] > 0) {
                //
                back += weight[id];
            } else {
                // �ö�������г������ٻ�������״̬ 
//                (0 - weight[id]) ȱ����Щ ��Ϊ���� 
                if(back > (0 - weight[id])) {
                    // ���back�����㹻�ģ��ȴ�back�п۳� 
//                    ���� back += һ������ 
                    back += weight[id];
//                    �������Ķ��� ���������� 
                } else {
//                	������������ 
                    // ���back��������ô��Ҫ��need�н� 
                    need += ((0 - weight[id]) - back);
//                    ȱ���� need �������� 
                    back = 0;
                }
            }
        }
        //������С������ 
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
            //������С�����д��������ٵ� 
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        // ������dfs���ʽ����󵯳� 
        temppath.pop_back();
        return ;
    }

    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
//        �յ������� 
    // �ö�����dfs���ʽ����󵯳� 
    temppath.pop_back();
}
int main() {
    // ��ʼ����ά����e 
    fill(e[0], e[0] + 510 * 510, inf);
    // ��ʼ������dis  
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        // ֱ�Ӽ���õ��������perfect״̬������ 
        weight[i] = weight[i] - cmax / 2;
//        ���� 0�� ���� -5  ����5�� 
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    // ����0������ľ�����Ȼ��0 
    dis[0] = 0;
    // ˫��forѭ����������ͼ��Dijkstra�㷨 
    // ���ѭ����ʾ����0~N������ 
//    ����û��vis 
    for(int i = 0; i <= n; i++) {
        // ѡ�����붥��0������С�Ķ���u
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        // ��ѭ����������ͨ��e������u�����������������С·�� 
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                // ����u���㵽v����ĸ�Сֵ 
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v] == dis[u] + e[u][v]) {
                    // u v ֮����ܴ��ڶ�����·�� 
                    pre[v].push_back(u);
//                    ����һ��· 
                }
            }
        }
    }
    // ��problem station �������������������ѡȡ���·�����������������һ�� 
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
} 
