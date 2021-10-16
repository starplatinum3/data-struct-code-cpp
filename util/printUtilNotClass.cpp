//
// Created by Lenovo on 2020/10/16.
//
#include "../mylib.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include "printUtilNotClass.h"
#include <stdarg.h>
//int println(const char *__format, ...) {
////    int printf (const char *__format, ...)
//     printf(__format, ...);
//    printf("\n");
//    //failed
//    return 1;
//}


//https://www.cnblogs.com/joyzhuang/p/4025270.html
int println(const char *fmt, ...)
{
    char printf_buf[1024];
    va_list args;
    int printed;
    va_start(args, fmt);
//    https://www.runoob.com/cprogramming/c-function-vsprintf.html
    printed = vsprintf(printf_buf, fmt, args);
    va_end(args);
//    puts(printf_buf);
    printf(printf_buf);
    putchar('\n');
    return printed;
}

void printArr(int *arr, int from, int to) {
    for (int i = from; i < to; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}


void printArr(int *arr, int len) {
    printArr(arr,0,len);

}




void printVector(const std::vector<double>& vector){
    for (auto val:vector){
        printf("%.2lf ",val);
    }
    putchar('\n');
}

void printVector(const std::vector<int>& vector){
    for (auto val:vector){
        printf("%d ",val);
    }
    putchar('\n');
}