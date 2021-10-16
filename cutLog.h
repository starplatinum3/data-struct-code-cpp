//
// Created by Lenovo on 2021/1/25.
//

#ifndef DATASTRUCT_CUTLOG_H
#define DATASTRUCT_CUTLOG_H

//https://blog.csdn.net/qq_44378358/article/details/103656215
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int dpMostMoney[1005];
int tryLen[1005];
int value[1005];

void tryCutLen(int tryLenIndex, int totLen) {
    for (int len = tryLen[tryLenIndex]; len <= totLen; len++) {
//            列举花费 tryLen[i]的长度 到 totLen 长度的话，最多可以得到多少钱
//len 列举长度
//我现在想切掉5 的长度，我看看我长度5的原木切掉5，两块东西加起来卖最多多少钱，
//再看看我长度6的原木切掉5，两块东西加起来卖最多多少钱，
//        再看看我长度7的原木切掉5，两块东西加起来卖最多多少钱，
//        再看看我长度8的原木切掉5，两块东西加起来卖最多多少钱，
//        再看看我长度9的原木切掉5，两块东西加起来卖最多多少钱，
//        再看看我长度10的原木切掉5，两块东西加起来卖最多多少钱，
//        。。。。
//        再看看我长度（原木总长）的原木切掉5，两块东西加起来卖最多多少钱，
// 这里举例的时候，切掉的长度不变，但是原来的长度变化
//这些都记录在dp里面
        dpMostMoney[len] = max(dpMostMoney[len], dpMostMoney[len - tryLen[tryLenIndex]] + value[tryLenIndex]);
//             我有 tryLen[i] 长度的话 可以得到value[i]的钱
//但是我的总长度少了 tryLen[tryLenIndex]
//我是总共长度len 来卖好呢，还是分成len- tryLen[i] 和 tryLen[i] 长度来卖好呢，有个比较
    }
}

int main() {
    int priceListCnt, totLen;
    cin >> totLen >> priceListCnt;
//    totLen 长度
//priceListCnt 个数据
//    花费原木的长度
    for (int i = 1; i <= priceListCnt; i++) {
        cin >> tryLen[i];
    }
//    会得到多少钱
    for (int i = 1; i <= priceListCnt; i++) {
        cin >> value[i];
    }
//    totLen 长度
//i 列举原木长度的下标
//我现在想切掉 你列表里第一个给出的长度的话，我两块加起来有多少钱啊
//我现在想切掉 你列表里第2个给出的长度的话，我两块加起来有多少钱啊
//我现在想切掉 你列表里第3个给出的长度的话，我两块加起来有多少钱啊
//我现在想切掉 你列表里第4个给出的长度的话，我两块加起来有多少钱啊
//。。。。
//我现在想切掉 你列表里第i个给出的长度的话，我两块加起来有多少钱啊
    for (int i = 1; i <= priceListCnt; i++) {
        tryCutLen(i, totLen);
    }
//    我总长这么多的木头 能卖多少钱啊
    cout << dpMostMoney[totLen];
    return 0;
}


#endif //DATASTRUCT_CUTLOG_H


void cutLog() {
    int totWeight;
    int valListLen;
    int weightListLen;
    int valList[111];
    int weightList[111];
    int dp[11];
    for (int i = 0; i < weightListLen; i++) {
        for (int tryWeight = weightList[i]; tryWeight <= totWeight; tryWeight++) {
            dp[tryWeight] = max(dp[tryWeight], dp[tryWeight - weightList[i]] + valList[i]);
        }
    }
    printf("%d\n",dp[totWeight]);
}