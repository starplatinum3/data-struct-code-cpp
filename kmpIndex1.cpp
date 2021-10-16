//
// Created by Lenovo on 2020/10/10.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


void get_next_val(char *T, int *next) {

    int j = 1, t = 0;
    //  t就是相同的最大前缀和最大后缀长，有可能是0的

    int len = strlen(T) + 1;
//    j 是字符串有关的 从1开始
    next[1] = 0;
    while (j < len) {
        if (t == 0 || T[j] == T[t]) {
//            这边多了一个前后缀可以匹配的 就可以多一个
            next[j + 1] = t + 1;
//            也就是字符串到j+1 下标的这个位置，他前后缀匹配有多少大
//因为字符串从1 开始，所以就是第j个字符，下标是1+j
//            这个是把算的 t + 1的值（就是相同的最大前缀和最大后缀长）赋给next[j + 1]
            j++;
            t++;
        } else t = next[t];
//        这里失败了 就找个次一点的长度吧
    }
}

int Index_KMP(char S[], char T[], int pos, int next[]) { //作用,子字符串第一次出现的位置.下标从1开始.
//S 原始字符串， T 需要的字符串
    int i = 1, t = 1;
//    next 和 T是有某些关系的
    int len1 = strlen(S + 1), len2 = strlen(T + 1);
    while (i <= len1 && t <= len2) {
        if (t == 0 || S[i] == T[t]) {
            t++;
            i++;
        } else t = next[t];
    }
//    i 到了某个位置 ，i是属于原始字符串的
//    (t > len2) 就是把需要的字符串 跑完了
    if (t > len2) return i - len2;
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


//正确的默写
int Index_KMP(char *str, char *needStr, int *next) {
    int len1 = strlen(str + 1);
    int len2 = strlen(needStr + 1);
    int i = 1, j = 1;
    while(i<=len1&&j<=len2){
        if(j==0||str[i]==needStr[j]){
            i++;
            j++;
        }else j=next[j];
    }
    if(j>len2)return i-len2;
    return 0;
}



