//
// Created by Lenovo on 2021/1/1.
//

#ifndef DATASTRUCT_LISTUTIL_H
#define DATASTRUCT_LISTUTIL_H

#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
//#include <cdoex.h>

//template<typename T>
template<typename T>
void printVector(std::vector<T> &vec) {
    using namespace std;
    cout << "print vector:" << endl;
    auto iter = vec.begin();
    while (iter != vec.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
}

class ListUtil {
//    template<typename T>
//    std::vector<T> data;
public:
    template<typename T>
    static void print(std::vector<T> vector);

    template<typename T>
    static void printVector(std::vector<T> &vec);


//    ————————————————
//    版权声明：本文为CSDN博主「danxinzhujian」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//    原文链接：https://blog.csdn.net/danxinzhujian/article/details/107150976

    template<typename T>
    static bool haveSame(std::vector<T> v1, std::vector<T> v2);

    template<typename T>
    static typename std::vector<T>::iterator find(std::vector<T> v, T val) {
        return std::find(v.begin(), v.end(), val);
    }

    template<typename T>
    static typename std::vector<T>::iterator isFound(std::vector<T> v, T val);

    template<typename T>
    static typename std::vector<T>::iterator notFound(std::vector<T> v, T val);

//public:
    static std::string toString(int *arr, int len);

    template<typename T>
    static std::string toString(std::vector<T> v);


    static int min(int *arr, int len);

    static int sum(const std::vector<int> &vector);

    static int list0Cnt(const int *arr, int len);

    static int listNumCnt(const int *arr, int len, int val);

//    static void printQueue(const std::queue<int >& queue);

    static void printQueue(std::queue<int> queue);
};

template<typename T>
void ListUtil::print(std::vector<T> vector) {
    for(auto val:vector){
//        std:: cout<<val<<" ";
        std::cout<<val<<" ";
//       using 的范围应该是在一个函数里面
    }
    putchar('\n');
}

//写在类里面就不行嘛 可以 但是要写在h 里面 ,简单的解决办法 不知道有没有别的办法,别的办法
//可能有 但也麻烦
//在这儿test.cpp中的内容应放在test.h中，否则在生成最终可执行程序时就会出现错误(在链接时会出错)
template<typename T>
void ListUtil::printVector(std::vector<T> &vec) {
    using  namespace std;
//    cout << "打印vector:" << endl;
    typename vector<T>::iterator iter = vec.begin();
    while (iter != vec.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
}

//https://blog.csdn.net/danxinzhujian/article/details/107150976


template<typename T>
typename std::vector<T>::iterator ListUtil::notFound(std::vector<T> v, T val) {
    return !isFound(v, val);
}

template<typename T>
typename std::vector<T>::iterator ListUtil::isFound(std::vector<T> v, T val) {
    return find(v, val) != v.end();
}

template<typename T>
bool ListUtil::haveSame(std::vector<T> v1, std::vector<T> v2) {
    for (auto val:v1) {
//            if (std::find(v2.begin(), v2.end(), val) != v2.end()) {
//                return true;
//            }
        if (isFound(v2, val)) {
            return true;
        }
    }
    return false;
}

template<typename T>
std::string ListUtil::toString(std::vector<T> v) {
    std::string str = "[";

    for (int i = 0; i < v.size() - 1; i++) {
        str += std::to_string(v[i]) + ", ";
    }
    str += std::to_string(v.back());
    str += "]";

    return str;
}

#endif //DATASTRUCT_LISTUTIL_H




