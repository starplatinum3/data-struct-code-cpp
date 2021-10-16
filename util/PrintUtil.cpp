//
// Created by Lenovo on 2021/1/1.
//

#include <iostream>
#include <cstdarg>
#include "PrintUtil.h"

void PrintUtil::test() {
    printf("test\n");
}


int PrintUtil::println(const char *fmt, ...) {
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

void PrintUtil::printMatrix(int matrix) {

}
