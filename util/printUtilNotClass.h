//
// Created by Lenovo on 2021/1/1.
//

#ifndef DATASTRUCT_PRINTUTILNOTCLASS_H
#define DATASTRUCT_PRINTUTILNOTCLASS_H

#include <vector>
template<class T>
void printVector(std::vector<T> v);

void printVector(std::vector<long long> v);

//D:/project/cppProject/datastruct/main.cpp:32: undefined reference to
// `printVector(std::vector<long long, std::allocator<long long> >)'
//
void printArr(int *arr, int from, int to) ;
void printArr(int *arr, int len) ;

void printVector(const std::vector<double>& vector);
void printVector(const std::vector<int>& vector);

template<class T>
void printVector(std::vector<T> v) {
    for (auto val:v) {
        std::cout << val << " ";
    }
    std::cout << "\n";
//    std::for_each(begin(some_list), end(some_list), [&, value, this](int x)
//    {
//        total += x * value * this->some_func();
//    });
//    https://www.cnblogs.com/jimodetiantang/p/9016826.html
}


#endif //DATASTRUCT_PRINTUTILNOTCLASS_H
