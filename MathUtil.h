//
// Created by Lenovo on 2021/1/1.
//

#ifndef DATASTRUCT_MATHUTIL_H
#define DATASTRUCT_MATHUTIL_H

#include <utility>
#include <vector>
#include <iostream>
#include "util/printUtilNotClass.h"
#include "util/ListUtil.h"


class MaxAndSecMaxNum {
    int *arr;

    int maxNum;
    int secMaxNum;
    int maxNumIndex;
    int secMaxNumIndex;
public:
    MaxAndSecMaxNum(int *arr, int maxNumIndex, int secMaxNumIndex);

    MaxAndSecMaxNum(const int *arr, int maxNumIndex, int secMaxNumIndex) : arr(const_cast<int *>(arr)),
                                                                           maxNumIndex(maxNumIndex),
                                                                           secMaxNumIndex(secMaxNumIndex) {}


    MaxAndSecMaxNum(int maxNum, int secMaxNum);

};

//c++没有元组这种方便的东西,当要返回两个数字的时候,需要用struct,但是我的愚蠢使我去使用class,但是一用class我就越写越复杂,本来
//我只是要返回两个数字啊,所以我感觉这种有多个数字要返回的,还是在一个类里面写,当作全局变量那样用,
//其实是class的类变量啦,反正class只是为了防止变量影响到外面的东西,里面基本还是函数式编程的,
//不过传递指针也可以,只是我感觉不太优雅,因为我是个弱鸡,指针不太会用,不太敢用
class MaxAndSecMaxNumVector {
    std::vector<int> v;
    int maxNum;
    int secMaxNum;
    int maxNumIndex;
    int secMaxNumIndex;
public:
    MaxAndSecMaxNumVector(std::vector<int> v, int maxNum, int secMaxNum, int maxNumIndex, int secMaxNumIndex)
            : v(std::move(v)), maxNum(maxNum), secMaxNum(secMaxNum), maxNumIndex(maxNumIndex),
              secMaxNumIndex(secMaxNumIndex) {}

    MaxAndSecMaxNumVector(std::vector<int> v, int maxNumIndex, int secMaxNumIndex) : v(std::move(v)),
                                                                                     maxNumIndex(maxNumIndex),
                                                                                     secMaxNumIndex(
                                                                                             secMaxNumIndex) {}

public:
    static MaxAndSecMaxNumVector GetSecondMaxNumberIndex(std::vector<int> arr) {
        int i;
//        max = arr[0];
        int maxIndex = 0;
        int secondMaxIndex = 0;
//        second_max = 0x80000000;
        for (i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[maxIndex]) {
//                second_max = max;
                secondMaxIndex = maxIndex;
//                max = arr[i];
                maxIndex = i;
            } else {
                if (arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                }
//                    second_max = arr[i];
            }
        }
//        std::cout<<max<<"  "<<second_max<<"\n";
        return MaxAndSecMaxNumVector(arr, maxIndex, secondMaxIndex);
    }
};

struct MaxAndSecMaxNumIndex {
    int maxIndex;
    int secondMaxIndex;
};

#include <algorithm>
#include <math.h>

class MathUtil {


public:

    static std::vector<long long> getFactorialList(int len);

    static std::vector<long long> getFactorialList() {
        return getFactorialList(10);
    }

//    35 : split 12 12 11 最平均分的整数，
    static std::vector<int> splitKNum(int num, int k) {
        using namespace std;
        vector<int> v;
        int ceilNum = ceil((double) num / k);
//        int floorNum = floor((double) num / k);
//        printf("ceilNum: %d, floorNum: %d\n", ceilNum, floorNum);
//        https://www.cnblogs.com/mycapple/archive/2012/08/07/2626431.html


// 如果是37 的话，我算出ceilNum 是37/3 ceil ==13，
// 我先所有都当作13
//13 13 13
//那我多加了哪些呢
//13*3 ==39
//39-37 ==2
//多加了2， 这个要减掉，每个减掉1就行了
        for (int i = 0; i < k; i++) {
            v.emplace_back(ceilNum);
        }
        int leftNum=ceilNum*k- num;
        for(int i=0;i<leftNum;i++){
            v[i]--;
        }

//        cout << ListUtil::toString(v) << "\n";
        return v;
    }

    static long long factorial(int to) {
        long long result = 1;
        for (int i = 1; i <= to; i++) {
            result *= i;
        }
        return result;
    }

//    https://blog.csdn.net/wang4862/article/details/79155383
    static MaxAndSecMaxNum GetSecondMaxNumber(const int *arr, int n) {

        int i, max, second_max;
        max = arr[0];
        second_max = 0x80000000;
        for (i = 1; i < n; ++i) {
            if (arr[i] > max) {
                second_max = max;
                max = arr[i];
            } else {
                if (arr[i] > second_max)
                    second_max = arr[i];
            }
        }
        std::cout << max << "  " << second_max << "\n";
        return {max, second_max};
    }

    static MaxAndSecMaxNum GetSecondMaxNumberIndex(const int *arr, int n) {
        int i;
//        max = arr[0];
        int maxIndex = 0;
        int secondMaxIndex = 0;
//        second_max = 0x80000000;
        for (i = 1; i < n; ++i) {
            if (arr[i] > arr[maxIndex]) {
//                second_max = max;
                secondMaxIndex = maxIndex;
//                max = arr[i];
                maxIndex = i;
            } else {
                if (arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                }
//                    second_max = arr[i];
            }
        }
//        std::cout<<max<<"  "<<second_max<<"\n";
        return {arr, maxIndex, secondMaxIndex};
    }

    static MaxAndSecMaxNumIndex GetSecondMaxNumberIndexRetStruct(const int *arr, int n) {
        int i;
//        max = arr[0];
        int maxIndex = 0;
        int secondMaxIndex = 0;
//        second_max = 0x80000000;
        for (i = 1; i < n; ++i) {
            if (arr[i] > arr[maxIndex]) {
//                second_max = max;
                secondMaxIndex = maxIndex;
//                max = arr[i];
                maxIndex = i;
            } else {
                if (arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                }
//                    second_max = arr[i];
            }
        }
//        std::cout<<max<<"  "<<second_max<<"\n";
        return {maxIndex, secondMaxIndex};
    }

    static int onlyOne0(const int *arr, int len) {

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0)cnt++;
        }
        return cnt == 1;
    }

    static int onlyOneNot0(const int *arr, int len) {
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] != 0)cnt++;
        }
        return cnt == 1;
    }

//没关系 最大的数字 肯定不是0
    static MaxAndSecMaxNumIndex GetSecondMaxNumberIndexRetStructIgnore0(const int *arr, int n) {
        int i;
//        max = arr[0];
        int maxIndex = 0;
        int secondMaxIndex = 0;
//        second_max = 0x80000000;
//        if (arr[0] == 0) {
//            maxIndex = 1;
//            secondMaxIndex = 1;
//        }
        for (i = 1; i < n; ++i) {
            if (arr[i] > arr[maxIndex]) {
//                second_max = max;
                secondMaxIndex = maxIndex;
//                max = arr[i];
                maxIndex = i;
            } else {
                if (arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                }
//                    second_max = arr[i];
            }
        }
//        std::cout<<max<<"  "<<second_max<<"\n";
        return {maxIndex, secondMaxIndex};
    }

    static void kWay() {
//        std::vector<int>v{17, 32, 56, 0};
        int arr[4] = {17, 32, 56, 0};
        int len = 4;
//        int secMaxIndex, maxIndex;
        while (!onlyOne0(arr, len)) {
//            printVector(v);
            printArr(arr, len);
//            MaxAndSecMaxNumVector maxAndSecMaxNumVector=MaxAndSecMaxNumVector::GetSecondMaxNumberIndex(v);
//            maxIndex,secMaxIndex=
            auto maxIndexAndSecMaxIndex = GetSecondMaxNumberIndexRetStruct(arr, len);
////        第二大的数字变成0
//            第一大的变成 - 去
//            第二大的数字
            arr[maxIndexAndSecMaxIndex.maxIndex] -= arr[maxIndexAndSecMaxIndex.secondMaxIndex];
            arr[maxIndexAndSecMaxIndex.secondMaxIndex] = 0;

        }
    }
};

#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include "util/ListUtil.h"
#include "util/printUtilNotClass.h"
#include<fstream>

//Polyphase Merge Sort
//纸带比way多1
class KWay {
//    目前可以正常计算纸带比way多1 的这种
//做题代码 不是真正的算法
    int secondMaxIndex;
    int maxIndex;
    int zeroIndex;
    int *arr;
    int len;
    bool simple;
    int notZeroIndex = 0;
public:
    KWay(int *arr, int len) : arr(arr), len(len) {}

    KWay(int *arr, int len, bool simple) : arr(arr), len(len), simple(simple) {}

//    这是一个错误的方法,但是写的挺辛苦的 所以暂时不删了
    void findMaxAndSecMaxMinus() {
        //        int arr[4] = {17, 32, 56, 0};
//        int len = 4;
//        int secMaxIndex, maxIndex;
        printf("纸袋%d路转换\n", len);
        std::string str;
        while (true) {
//            printVector(v);

            printArr(arr, len);
            str += ListUtil::toString(arr, len) + "\n";

            if (MathUtil::onlyOne0(arr, len)) {
                break;
            }
//            MaxAndSecMaxNumVector maxAndSecMaxNumVector=MaxAndSecMaxNumVector::GetSecondMaxNumberIndex(v);
//            maxIndex,secMaxIndex=
//            auto maxIndexAndSecMaxIndex = GetSecondMaxNumberIndexRetStruct(arr, len);
////        第二大的数字变成0
//            第一大的变成 - 去
//            第二大的数字
            GetSecondMaxNumberIndex();
            arr[maxIndex] -= arr[secondMaxIndex];
            arr[zeroIndex] = arr[secondMaxIndex];
            arr[secondMaxIndex] = 0;

        }
//        https://www.cnblogs.com/li-ning/p/9490053.html
//        std::ofstream fout;
//        fout.open("kWay.csv");
        std::ofstream fout("kWay.csv");
        fout << str;
        std::cout << str << "\n";
        fout << std::flush;
        fout.close();
//        std::ifstream fin("E:\\download2\\kWay.csv");
//        fin>>str;
//        fin.close();
    }

    static int onlyOneNot0(const int *arr, int len) {
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] != 0)cnt++;
        }
        return cnt == 1;
    }

    int onlyOneNot0() {
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] != 0) {
                cnt++;
                notZeroIndex = i;
            }
        }
//        printf("notZeroIndex:%d\n", notZeroIndex);
        return cnt == 1;
    }

    void putNums(std::vector<int> v) {
        int vIndex = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0) {
                arr[i] = v[vIndex++];
            } else {
                arr[i] = 0;
            }
        }
    }

    void run() {
        printf("纸带%d条，%d路%s归并\n", len, len - 1, simple ? "简单" : "");
        printf("尽量所有的数字都减去相同的，减不够了就开始下一轮\n");
        printf("比如 17   32   56    0 开始的话，先都-17,17被消耗没了，然后三个17合并在一起了，会在右边那个0那边\n");
        std::string str;
        int cnt = 0;
        while (true) {
            if (cnt > 100) {
                printf("循环超出100,肯定哪里有错误了,调试下吧\n");
                break;
            }
//            printVector(v);
            printArr(arr, len);
//            str += ListUtil::toString(arr, len) + "\n";
//            MathUtil::onlyOneNot0(arr, len)
            if (onlyOneNot0()) {
//                如果是简单归并的话 这里要分开了 如果有3个0 就把数字分成3份
                if (!simple)
                    break;
//                len-1 是k
                if (arr[notZeroIndex] == 1)break;
//                0 0 0 1 这样子的 就是可以退出了 已经做好了
                std::vector<int> numsAve = MathUtil::splitKNum(arr[notZeroIndex], len - 1);
//                std::cout << ListUtil::toString(numsAve) << "\n";
                putNums(numsAve);
                printArr(arr, len);
                cnt++;
            }
//            MaxAndSecMaxNumVector maxAndSecMaxNumVector=MaxAndSecMaxNumVector::GetSecondMaxNumberIndex(v);
//            maxIndex,secMaxIndex=
//            auto maxIndexAndSecMaxIndex = GetSecondMaxNumberIndexRetStruct(arr, len);
////        第二大的数字变成0
//            第一大的变成 - 去
//            第二大的数字
//            GetSecondMaxNumberIndex();
            int minIndex = getMinNot0();
            if (minIndex == -1) {
//                全是0
                break;
            }
//            0 放最小数字
//其他不是0的位置,- 最小数字
//4 tape 出现两个0的话,那个0 就不管了
            int minNum = arr[minIndex];
            for (int i = 0; i < len; i++) {
                if (arr[i] == 0)continue;
//                if(arr[i]==arr[minIndex])continue;
                arr[i] -= minNum;
//    if(arr[i]==arr[minIndex])
            }
            arr[zeroIndex] = minNum;

//            arr[maxIndex] -= arr[secondMaxIndex];
//            arr[zeroIndex] = arr[secondMaxIndex];
//            arr[secondMaxIndex] = 0;
            cnt++;

        }
        printf("进行了%d步\n", cnt);
//        https://www.cnblogs.com/li-ning/p/9490053.html
//        std::ofstream fout;
//        fout.open("kWay.csv");



//        std::ofstream fout("kWay.csv");
//        fout << str;
//        std::cout << str << "\n";
//        fout << std::flush;
//        fout.close();
    }

private:
//    找出一个数组最小的数字的下标 除了0的,顺便把0的下标也找了
    int getMinNot0() {
        int minIndex = 0;
//        if (arr[0] == 0)minIndex = 1;
        while (arr[minIndex] == 0)minIndex++;
        if (minIndex >= len) {
            printf("全是0，有问题\n");
            return -1;
        }
        for (int i = 0; i < len; i++) {
            if (arr[i] == 0) {
                zeroIndex = i;
                continue;
            }
//            todo
            if (arr[minIndex] > arr[i]) {
                minIndex = i;
            }
        }
//        printf("min num:%d\n",arr[minIndex]);
        return minIndex;
    }

    void GetSecondMaxNumberIndex() {
        int i;
//        max = arr[0];
//        int maxIndex = 0;
//        int secondMaxIndex = 0;
//        second_max = 0x80000000;
        for (i = 0; i < len; ++i) {
            if (arr[i] == 0) {
                zeroIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
//                second_max = max;
                secondMaxIndex = maxIndex;
//                max = arr[i];
                maxIndex = i;
            } else {
                if (arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                }
//                    second_max = arr[i];
            }
        }
//        std::cout<<max<<"  "<<second_max<<"\n";

    }

};

#endif //DATASTRUCT_MATHUTIL_H
