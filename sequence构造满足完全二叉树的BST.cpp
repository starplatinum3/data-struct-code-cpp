#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> Vec, res;

void getLevelOrder(int st, int ed, int idx) {
    if (st > ed)return;
    int n = ed - st + 1;//ע�������nΪ��ǰ�����Ľ�������n��������Ϊȫ�ֱ�����
//    n �Ѿ���1 �� �ǽ�����
//    6
//    https://blog.csdn.net/wwxy1995/article/details/89251455
    int h = log2(n + 1);  // ���ĸ߶�
//    ���ĸ߶�����0 ��
    int leaf = n - (pow(2, h) - 1);  // ���һ�������.
//    ��Ϊÿ�㶼�ǳɱ��ɱ������� ����root ��1�� ���� -1
//    (pow(2, h) - 1) ���������
//    int leaf = n + 1 - pow(2, h);  // ���һ�������.
//    int nodeCntExceptLastLevel=pow(2, h);  //�������һ��Ľ�����
//    int leaf = n + 1-nodeCntExceptLastLevel;  // ���һ�������.
//    printf("nodeCntExceptLastLevel : %d\n",nodeCntExceptLastLevel);
    int lastLevLeftTreeCnt = min((int) pow(2, h - 1), leaf);
    // ���һ���������ĸ���
//    (pow(2, h - 1) - 1) + lastLevLeftTreeCnt; // �����������
    int leftNodeCnt = (pow(2, h - 1) - 1) + lastLevLeftTreeCnt;// �����������

    int rootIdx = st + leftNodeCnt;
    printf("\n");
    printf("node cnt : %d\n",n);
    printf("leftNodeCnt : %d\n",leftNodeCnt);
    printf("st + (pow(2, h - 1) - 1) + lastLevLeftTreeCnt\n");
    printf("%d %.0f %d\n", st, (pow(2, h - 1) - 1), lastLevLeftTreeCnt);
    printf("st: %d , ed: %d , index : %d\n", st, ed, idx);
    printf("h: %d, leaf: %d, rootIdx: %d\n", h, leaf, rootIdx);
    res[idx] = Vec[rootIdx];
//    st �Ƕ��� ������������
//    res �ǲ��������
    getLevelOrder(st, rootIdx - 1, 2 * idx + 1);
    getLevelOrder(rootIdx + 1, ed, 2 * idx + 2);
}

//6
//1 2 3 4 5 6
int main() {
    string str;
//    transform(str.begin().str.end(),str.begin(),::tolower/::toupper);
//    https://blog.csdn.net/fengbingchun/article/details/63252470
    transform(str.begin(),str.end(),str.begin(),::tolower);
//    fabs(1.1);


    int n;
    cin >> n;
    Vec.resize(n);
    res.reserve(n);
//    Ҫ�� 0 ��ͷ��
    for (int i = 0; i < n; i++) cin >> Vec[i];
    sort(Vec.begin(), Vec.end());
    getLevelOrder(0, n - 1, 0);
    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i != n - 1) cout << " ";
    }
    return 0;
}

