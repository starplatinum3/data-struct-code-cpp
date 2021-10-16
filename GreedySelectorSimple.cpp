//
// Created by Lenovo on 2020/12/23.
//
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

const int N = 11;

struct Event{
    int s;
    int f;
    int chosen;
    bool operator<(const Event &ano) const {
        return f < ano.f;
    }

    Event(int s, int f) : s(s), f(f) {}
};

/**
 *
 * @tparam Type
 * @param n num
 * @param s start
 * @param f  finish
 * @param A
 * 贪心算法】活动安排问题
 * @link https://blog.csdn.net/u013854486/article/details/102845400 @endlink
 */
void GreedySelector(int n, int s[], int f[], bool A[]) {
    A[1] = true;
//    第一个活动就是一定的 加入
    int j = 1;//记录最近一次加入A中的活动

    for (int i = 2; i <= n; i++)//依次检查活动i是否与当前已选择的活动相容
    {
        if (s[i] >= f[j]) {
            A[i] = true;
            j = i;
        } else {
            A[i] = false;
        }
    }
}

void GreedySelector(vector<Event> &events) {
    events[0].chosen = true;
//    第一个活动就是一定的 加入
    int j = 0;//记录最近一次加入A中的活动

    for (int i = 1; i < events.size(); i++)//依次检查活动i是否与当前已选择的活动相容
    {
        if (events[i].s>= events[j].f) {
            events[i].chosen = true;
            j = i;
        } else {
            events[i].chosen = false;
        }
    }
}




int mainGreedySelector() {
    //下标从1开始,存储活动开始时间
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};

    //下标从1开始,存储活动结束时间
    int f[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    bool A[N + 1];

    vector<Event>events;
    for (int i = 1; i <= N; i++) {
        events.emplace_back(s[i], f[i]);
    }
    sort(events.begin(),events.end());
    GreedySelector(events);
    int cnt=0;

    cout << "最大相容活动子集为：" << endl;
    for(auto e:events){
        cnt++;
        if(e.chosen){
            cout << "[" << cnt << "]:" << "(" << e.s << "," <<e.f << ")" << endl;
        }
    }


    cout << "各活动的开始时间,结束时间分别为：" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "[" << i << "]:" << "(" << s[i] << "," << f[i] << ")" << endl;
    }
    GreedySelector(N, s, f, A);
    cout << "最大相容活动子集为：" << endl;
    for (int i = 1; i <= N; i++) {
        if (A[i]) {
            cout << "[" << i << "]:" << "(" << s[i] << "," << f[i] << ")" << endl;
        }
    }


    return 0;
}

