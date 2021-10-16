//
// Created by Lenovo on 2021/1/25.
//

#ifndef DATASTRUCT_KMP_H
#define DATASTRUCT_KMP_H
//https://pintia.cn/problem-sets/1314767576917401600/problems/1314767641505488897
#include <string.h>
void get_nextval(char T[],int next[]){

    int j = 1, t = 0;
    int len = strlen(T)+1;
    next[1] = 0;
    while(j < len){
        if(t == 0 || T[j] == T[t]){
            next[j+1] = t+1;
            j++; t++;
        }
        else t = next[t];
    }
}

int Index_KMP(char  S[], char T[],int pos, int next[]){ //作用,子字符串第一次出现的位置.下标从1开始.

    int i = 1, j = 1;
    int len1 = strlen(S+1), len2 = strlen(T+1);
    while(i <= len1 && j <= len2){
        if(j == 0 || S[i] == T[j]){
            j++; i++;
        }
        else j = next[j];
    }
    if(j > len2) return i - len2;
    else return 0;
}

#include<cstring>
#include<iostream>
using namespace std;

#define MAXSTRLEN 255

void get_nextval(char T[], int next[]);
int Index_KMP(char S[], char T[], int pos, int next[]);

int main()
{
    char S[MAXSTRLEN+1],T[MAXSTRLEN+1];
    char S1[MAXSTRLEN],S2[MAXSTRLEN];
    cin >> S1 >> S2;
    strcpy(&S[1],S1);
    strcpy(&T[1],S2);
    S[0]=strlen(S1);
    T[0]=strlen(S2);
    int *next = new int[T[0]+1];
    get_nextval(T,next);
    cout<<Index_KMP(S,T,1,next);
    return 0;
}

/* 请在这里填写答案 */
#endif //DATASTRUCT_KMP_H
