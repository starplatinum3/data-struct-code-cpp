//1003 Emergency (25 ��)


//���·  ��·�����о�Ԯ�ӵ�������·������
#include <bits/stdc++.h> //a

using namespace std;

const int N = 555;
const int inf = 0x3f3f3f3f;
int re[N], res[N];
int leng[N][N], path[N];

vector<int> p;
int length[N], vis[N], ro[N], n, s;
// �Ե�
void dij() {
    memset(length, inf, sizeof(length));
    memset(path, -1, sizeof(path));
    ro[s] = 1;
    length[s] = 0;
    res[s] = re[s];
    while (true) {
        int v = -1;
        for (int j = 0; j < n; j++) {
//        	������С����� �� 
            if (!vis[j] && (v == -1 || length[j] < length[v])) {
                v = j;
            }
        }
//        �ҵ���С���� 
//        ����С�� 
        if (v == -1)break;
        vis[v] = 1;
        // ����v ��ŶŶ����������v�ģ� prio�Ǳ�������u��
    
        for (int u = 0; u < n; u++) {
            if (vis[u] == 0) {
                // Ϊʲô��u ��ǰ��
                // Ϊʲô�⻹�ǶԵ�
                // ���� ������ʽ�� ����u����� ,prio�ľ���v�����
                if (length[u] > length[v] + leng[v][u]) {
                    length[u] = length[v] + leng[v][u];
//                    ���Ǹı��· 
                    ro[u] = ro[v];
                    res[u] = re[u] + res[v];
                    path[u] = v;
                } else if (length[u] == length[v] + leng[v][u]) {
//                	���ӵ�· 
                    ro[u] += ro[v];
                    // ���Ӿ�Ԯ��
                    if (res[u] < res[v] + re[u]) {
                        res[u] = res[v] + re[u];
                        path[u] = v;
                    }
                }
            }
        }
    }
}

void showPath(int d) {
    int a = d;
    while (a != -1) {
        p.push_back(a);
   
        a = path[a];
    }
    int fir = 1;
    for (int i = p.size() - 1; i >= 0; i--) {
        if (fir) {
            printf("%d", p[i]);
            fir = 0;
        } else {
            printf(" %d", p[i]);
        }
    }
}

int main() {
    printf("dij\n");
    int m, d, i;
//    n��ĸ�����m���ߣ�s��ʼ��d��
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (i = 0; i < n; i++) {
        scanf("%d", re + i);
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) leng[i][j] = 0;
            else leng[i][j] = inf;
        }
    }
    for (i = 1; i <= m; i++) {
        int a, b, len;
        scanf("%d%d%d", &a, &b, &len);
        leng[a][b] = leng[b][a] = len;

    }
    dij();
    printf("%d %d\n", ro[d], res[d]);//·�������� ��Ԯ����������
    showPath(d);
}
