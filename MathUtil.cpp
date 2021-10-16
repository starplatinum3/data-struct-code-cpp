//
// Created by Lenovo on 2021/1/1.
//

#include "MathUtil.h"
/**
 * 这个用long long 能获得的大概也就10几个是正确的 剩下的都超过long long范围了
 * @param len
 * @return
 */
std::vector<long long> MathUtil::getFactorialList(int len) {
    std::vector<long long int> factorialList{0, 1};
    for (int i = 2; i < len; i++) {
//        1*2
        factorialList.emplace_back(factorialList.back() * i);
    }
    return factorialList;
}

MaxAndSecMaxNum::MaxAndSecMaxNum(int maxNum, int secMaxNum) : maxNum(maxNum), secMaxNum(secMaxNum) {}

MaxAndSecMaxNum::MaxAndSecMaxNum(int *arr, int maxNumIndex, int secMaxNumIndex) : arr(arr), maxNumIndex(maxNumIndex),
                                                                                  secMaxNumIndex(secMaxNumIndex) {}

