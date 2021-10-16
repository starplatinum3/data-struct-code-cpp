#include<bits/stdc++.h>
///
using namespace std;

int largestRectArea(vector<int> &height) {
    stack<int> p;
    int i = 0, res = 0;
    height.push_back(0);//作用：清空栈
//    p.push_back(0);//作用：清空栈
//    p.push(0);//作用：清空栈
    while (i < height.size()) {
//        放在栈里的 就是选取的行了
//如果 1 行是 5高，2行是 6高，那么2行也是 push，可以形成 2*5 的矩阵
printf("============\n");
//        {2, 1, 5, 6, 2, 3};
//2 1

//2 3
//1*3
//2*4 (5 6 2 3
//1 *6
//最后的高度是 0 ，为了 顺利结束而造的数据
//i 走到 3 往后退 到 2
//3 能退到 5 吗  不能， 因为到5 的话 就是 2 作为最小了
//也就是往后退只能退到比他小的
//i 走到 3 （最后一个 只能退到 2，去算一下 2 3 ，是 2 2 ， 2*2==4
//为什么是 4个，因为   5 6  2  3
        cout<<"i: "<<i<<"\n";
        if (p.empty() || height[p.top()] <= height[i]) {
//            cout<<"i: "<<i<<"\n";
            if (!p.empty()) {
                cout << " height[p.top()]: " << height[p.top()] << "\n";
            }
            cout << "height[i]: " << height[i] << "\n";
            p.push(i++);
//            如果下一个比他高就进栈
        } else {
            //如果 1 行是 6高，2行是 5高，那么2行不能算，要从2行重新开始了
//            但是要先算一下目前的最大面积，p top 是上一个这么高的
//比如 1 是 5 ，2  6， 3 6 ， 4 4
//在4 的时候 ，要重新计算了，p有的就是 1,4-1 -1 距离是2 ，为啥是2 呢
//貌似不是我想的那样
//1 2  3
//1 5 6
            int t = p.top();
            p.pop();
//            int cnt=i - p.top() - 1;
//            cout<<"cnt :" <<cnt<<"\n";
            if (!p.empty()) {
                cout<<"p.top() : "<<p.top()<<"\n";
                cout << "i - p.top() - 1 ： " << i - p.top() - 1 << "\n";
            }
//            6 只有 一个这么高的
//5  有两个，为什么呢， 因为6 是5 之后的，比他高，肯定多了这个 而且是他之后一个
            cout<<"height[t]: "<<height[t]<<"\n";
            res = max(res, height[t] * (p.empty() ? i : i - p.top() - 1));
//            res = max(res, height[t] * (p.empty() ? i :cnt ));
//            0 1 2 3 。。
//2 -1
        }
    }
    return res;
}

//https://blog.csdn.net/liql2007/article/details/9365383
int main() {
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << largestRectArea(v);
}