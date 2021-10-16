//
// Created by Lenovo on 2020/10/10.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


void get_next_val(char *T, int *next) {

    int j = 1, t = 0;
    int len = strlen(T) + 1;
    next[1] = 0;
    while (j < len) {
        if (t == 0 || T[j] == T[t]) {
            next[j + 1] = t + 1;
            j++;
            t++;
        } else t = next[t];
    }
}

int Index_KMP(char S[], char T[], int pos, int next[]) { //作用,子字符串第一次出现的位置.下标从1开始.

    int i = 1, j = 1;
    int len1 = strlen(S + 1), len2 = strlen(T + 1);
    while (i <= len1 && j <= len2) {
        if (j == 0 || S[i] == T[j]) {
            j++;
            i++;
        } else j = next[j];
    }
    if (j > len2) return i - len2;
    else return 0;
}

//https://blog.csdn.net/weixin_44031744/article/details/86657987
//字符串下标从1开始的kmp
int testKmpIndex1() {
    char originString[1000], pattenString[666];
    int Next[666];
    scanf("%s", originString + 1);
    scanf("%s", pattenString + 1);

    get_next_val(pattenString, Next);

    cout << Index_KMP(originString, pattenString, 1, Next) << endl;
    return 0;
}

