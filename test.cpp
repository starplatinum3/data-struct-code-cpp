//
// Created by Lenovo on 2020/12/24.
//
#include <stdio.h>
int main(){
    int x,y;
    scanf("%2d%*2s%2d", &x, &y);
    printf("%d", x+ y);
    return 0;
}