
//#include "stdafx.h"
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

template<class Type>
void GreedySelector(int n, Type s[], Type f[], bool A[]);

const int N = 11;

template<class Type>
class Event {
//    template<class Type>
private:
    Type startTime;
    Type finishTime;
    bool chosen;
public:
    Event(Type startTime, Type finishTime) : startTime(startTime), finishTime(finishTime) {}

    bool isChosen() const {
        return chosen;
    }

public:
    void setChosen(bool chosen) {
        Event::chosen = chosen;
    }

    Type getStartTime() const {
        return startTime;
    }

    Type getFinishTime() const {
        return finishTime;
    }

    bool operator<(const Event &ano) const {
        return finishTime < ano.finishTime;

    }

    static void GreedySelector(vector<Event<int>> &events) {
        //    vector<Event>vector;
        sort(events.begin(), events.end());
//    activities[0] = true;
        events[0].setChosen(true);

//    第一个活动就是一定的 加入
        int j = 0;//记录最近一次加入A中的活动
        int len = events.size();

        for (int i = 1; i < len; i++)//依次检查活动i是否与当前已选择的活动相容
        {
//        活动选不选
//这个活动开始的时间 比j晚了
            if (events[i].getStartTime() >= events[j].getFinishTime()) {
//            activities[i] = true;
                events[i].setChosen(true);
                j = i;
            } else {
//            activities[i] = false;
                events[i].setChosen(false);
            }
        }
    }

};

int mainGreedySelector() {
    //下标从1开始,存储活动开始时间
//    int s[] = {0, 1, 2, 3, 3, 5, 5, 6, 8, 11, 12};
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
vector<int> startTimes{0, 1, 2, 3, 3, 5, 5, 6, 8, 11, 12};


    //下标从1开始,存储活动结束时间
//    int f[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int f[] = {6, 4, 14, 5, 9, 7, 9, 10, 11, 12, 16};
    vector<int>finishTimes{6, 4, 14, 5, 9, 7, 9, 10, 11, 12, 16};
    bool A[N + 1];

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

    vector<Event<int>> events;
    for (int i = 0; i <startTimes.size(); i++) {
        events.emplace_back(startTimes[i], finishTimes[i]);
    }
//    new Event<int>(1,1);
//    Event<int>(1,1).GreedySelector()
//    Event<int>.GreedySelector();
    Event<int>::GreedySelector(events);
    int cnt=0;
    for(auto e:events){
        cnt++;
        if(e.isChosen()){
            cout<<" getStartTime:"<<e.getStartTime()<<". finish: "<<e.getFinishTime()<<" , cnt: "<< cnt<<"\n";
        }
    }
//    https://blog.csdn.net/quantum7/article/details/89006659

    return 0;
}


template<class Type>
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
void GreedySelector(int n, Type s[], Type f[], bool A[]) {
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
//https://blog.csdn.net/u013854486/article/details/102845400


//template<class Type>
/**
 *
 * @tparam Type
 * @param n num
 * @param s start
 * @param f  finish
 * @param activities
 * 贪心算法】活动安排问题
 * 从0 开始 activities
 * @link https://blog.csdn.net/u013854486/article/details/102845400 @endlink
 */
void GreedySelector(vector<Event<int>> &events) {
//    vector<Event>vector;
    sort(events.begin(), events.end());
//    activities[0] = true;
    events[0].setChosen(true);

//    第一个活动就是一定的 加入
    int j = 0;//记录最近一次加入A中的活动
    int len = events.size();

    for (int i = 1; i < len; i++)//依次检查活动i是否与当前已选择的活动相容
    {
//        活动选不选
        if (events[i].getStartTime() >= events[j].getFinishTime()) {
//            activities[i] = true;
            events[i].setChosen(true);
            j = i;
        } else {
//            activities[i] = false;
            events[i].setChosen(false);
        }
    }

//    i 是活动编号，如果 true 就是选择这个活动
}
//https://www.cnblogs.com/yuzhuwei/p/4171070.html
//模板