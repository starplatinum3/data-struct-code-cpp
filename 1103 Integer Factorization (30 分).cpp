/**
����: ����N, K, P; ��N��ʾ��K����������P�η��ĺͣ�����ж��з�������ôѡ��n1 + .. nk�����ķ�����
������ж��ַ�����ѡ�����е��ֵ������ķ�����
**/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, k, p;
int maxFacSum = -INF;//������֮��
vector<int> fac, ans, temp;//���ŵ������к���ʱ����
/**
��n^p
**/
int power(int x) {
    int ans = 1;
//    p ��2 �Ļ� ����
//	tmp: 0
//tmp: 1
//tmp: 4
//tmp: 9
//tmp: 16
//tmp: 25
//tmp: 36
//tmp: 49
//tmp: 64
//tmp: 81
//tmp: 100
//tmp: 121
//tmp: 144   �� ���ѡ��� 
    for (int i = 0; i < p; i++) {
        ans *= x;
    }
    return ans;
}
/**
��ʼ��fac����ע��0
**/
void init() {
    int i = 0, tmp = 0;
    while (tmp <= n) {
        fac.push_back(tmp);
        cout<<"tmp: "<<tmp<<", i : "<<i<<"\n";
        tmp = power(++i);
    }
}
/**
DFS����
index: ��ǰ���ʣ�
nowK:��ǰѡ�и���
sum:��ǰ�����ĺ�
facSum:��ǰ�ĵ����ĺ�, n1 + n2 +... + nk;
**/
 
void DFS(int index, int nowK, int sum, int facSum) {
    if (sum > n || nowK > k) return;
    if (sum == n && nowK == k) {
        if (facSum > maxFacSum) {
            maxFacSum = facSum;
            ans = temp;
        }
        return;
    }
    if (index - 1 >= 0) {//fac[0]����Ҫ
        //ѡindex
        // ��Ϊ�Ǵ�index ��Ŀ�ʼѡ�� 
        // ��������� facSum > maxFacSum ���£� ����ѡ�˴��֮����С�ģ� С��Ҫ����
        // �������ѡ��С��
        temp.push_back(index);
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        //��ѡindex
        // ��ǰ���Ǵ��
        temp.pop_back();
        DFS(index - 1, nowK, sum, facSum);
    }
}


void DFS(int index, int nowK, int sum, int facSum) {
    if (sum > n || nowK > k) return;
    if (sum == n && nowK == k) {
        if (facSum >= maxFacSum) {
            maxFacSum = facSum;
            ans = temp;
        }
        return;
    }
    if (index - 1 >= 0) {//fac[0]����Ҫ
        //ѡindex
        // ��Ϊ�Ǵ�index ��Ŀ�ʼѡ�� 
        // ��������� facSum > maxFacSum ���£� ����ѡ�˴��֮����С�ģ� С��Ҫ����
        // �������ѡ��С��
        // ����Ҳ��������  ��ѡ��С�ģ� ������С��֮�� ���������ĺ�С��ͬ��
        // ���� ��facSum >= maxFacSum�� Ҳ��Ҫ���µ�
        DFS(index - 1, nowK, sum, facSum);

        temp.push_back(index);
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        //��ѡindex
        // ��ǰ���Ǵ��
        temp.pop_back();
        
    }
}




//https://www.baidu.com/link?url=M-FULpWyMeSYEB6EKyG3BtNT-l4jI6VZc_4ZWbCgWVRnPzFTU6Qw_MGHxkn_qXtFyN3M1EGiUYzs9zmH2zgDcIjnkfajjaU0-PJ-u7OhgRi&wd=&eqid=c883f1060012a62f000000056044e6d0
int main() {
    cin >> n >> k >> p;
//    n  sum 
    init();
    DFS(fac.size() - 1, 0, 0, 0);
    if (maxFacSum == -INF) cout << "Impossible" << endl;
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size(); i++) {
            printf(" + %d^%d", ans[i], p);
        }
        printf("\n");
    }
	return 0;
}
