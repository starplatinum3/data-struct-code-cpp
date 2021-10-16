#include<bits/stdc++.h>
///
using namespace std;

int largestRectArea(vector<int> &height) {
    stack<int> p;
    int i = 0, res = 0;
    height.push_back(0);//作用：清空栈
    while(i < height.size()) {
//        放在栈里的 就是选取的行了
//如果 1 行是 5高，2行是 6高，那么2行也是 push，可以形成 2*5 的矩阵
        if(p.empty() || height[p.top()] <= height[i])
            p.push(i++);
        else {
            int t = p.top();
            p.pop();
            int cnt=i - p.top() - 1;
            cout<<
            res = max(res, height[t] * (p.empty() ? i : i - p.top() - 1 ));
//            0 1 2 3 。。
//2 -1
        }
    }
    return res;
}

//https://blog.csdn.net/liql2007/article/details/9365383
int main(){

}