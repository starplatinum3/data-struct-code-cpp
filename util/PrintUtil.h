//
// Created by Lenovo on 2021/1/1.
//

#ifndef DATASTRUCT_PRINTUTIL_H
#define DATASTRUCT_PRINTUTIL_H

#include <vector>

class PrintUtil {

//    template<class T, class T>
//    void printVector(const std::vector<T> &v);
public:
    template<typename T>
    static void printVector(std::vector<T> v);

    static void test();
    void printMatrix(int matrix);


//https://www.cnblogs.com/joyzhuang/p/4025270.html
    static  int println(const char *fmt, ...);

};

//https://blog.csdn.net/Unsigned_short/article/details/84649506
//template<class T>
template<typename T>
void PrintUtil::printVector(std::vector<T> v) {
    for (T val:v) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}



#endif //DATASTRUCT_PRINTUTIL_H
