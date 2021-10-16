#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> Vec, res;

void getLevelOrder(int st, int ed, int idx) {
    if (st > ed)return;
    int n = ed - st + 1;//注意这里的n为当前子树的结点个数，n不能声明为全局变量。
//    n 已经加1 了 是结点个数
//    6
//    https://blog.csdn.net/wwxy1995/article/details/89251455
    int h = log2(n + 1);  // 树的高度
//    根的高度算是0 吗
    int leaf = n - (pow(2, h) - 1);  // 最后一层结点个数.
//    因为每层都是成倍成倍的增加 但是root 是1个 所以 -1
//    (pow(2, h) - 1) 上面结点个数
//    int leaf = n + 1 - pow(2, h);  // 最后一层结点个数.
//    int nodeCntExceptLastLevel=pow(2, h);  //除了最后一层的结点个数
//    int leaf = n + 1-nodeCntExceptLastLevel;  // 最后一层结点个数.
//    printf("nodeCntExceptLastLevel : %d\n",nodeCntExceptLastLevel);
    int lastLevLeftTreeCnt = min((int) pow(2, h - 1), leaf);
    // 最后一层左子树的个数
//    (pow(2, h - 1) - 1) + lastLevLeftTreeCnt; // 左子树结点数
    int leftNodeCnt = (pow(2, h - 1) - 1) + lastLevLeftTreeCnt;// 左子树结点数

    int rootIdx = st + leftNodeCnt;
    printf("\n");
    printf("node cnt : %d\n",n);
    printf("leftNodeCnt : %d\n",leftNodeCnt);
    printf("st + (pow(2, h - 1) - 1) + lastLevLeftTreeCnt\n");
    printf("%d %.0f %d\n", st, (pow(2, h - 1) - 1), lastLevLeftTreeCnt);
    printf("st: %d , ed: %d , index : %d\n", st, ed, idx);
    printf("h: %d, leaf: %d, rootIdx: %d\n", h, leaf, rootIdx);
    res[idx] = Vec[rootIdx];
//    st 是对于 中序遍历数组的
//    res 是层序遍历的
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
//    要是 0 开头的
    for (int i = 0; i < n; i++) cin >> Vec[i];
    sort(Vec.begin(), Vec.end());
    getLevelOrder(0, n - 1, 0);
    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i != n - 1) cout << " ";
    }
    return 0;
}

