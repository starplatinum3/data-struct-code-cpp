//
// Created by Lenovo on 2021/1/1.
//

//#ifndef DATASTRUCT_LISTUTIL_H
//#define DATASTRUCT_LISTUTIL_H

#include <vector>

#include <iostream>
#include "ListUtil.h"

//#endif //DATASTRUCT_LISTUTIL_H



void ListUtil::printQueue(std::queue<int> queue) {
    for (; !queue.empty();) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
}

int ListUtil::listNumCnt(const int *arr, int len, int val) {
    //        std::find(arr,arr+len,val);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == val)cnt++;
    }
    return cnt;
}

int ListUtil::list0Cnt(const int *arr, int len) {
    return listNumCnt(arr, len, 0);
}

int ListUtil::sum(const std::vector<int> &vector) {
    int sum = 0;
    for (auto val:vector) {
        sum += val;
    }
    return sum;
}

int ListUtil::min(int *arr, int len) {
    int minIndex = 0;
    for (int i = 0; i < len; i++) {
        if (arr[minIndex] > arr[i]) {
            minIndex = i;
        }
    }
    return arr[minIndex];
}


std::string ListUtil::toString(int *arr, int len) {
    std::string str;
    for (int i = 0; i < len - 1; i++) {
//                str+=arr[i]+" ";
        str += std::to_string(arr[i]) + ",";
//                https://blog.csdn.net/program_anywhere/article/details/63720261
//                str.append(arr[i]);
    }
    str += std::to_string(arr[len - 1]);
//        str += "\n";
    return str;
}




