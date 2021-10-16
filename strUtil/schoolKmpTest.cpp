//
// Created by Lenovo on 2020/10/10.
//

#include<cstring>
#include<iostream>
using namespace std;

#define MAXSTRLEN 255

void get_next_val(char *T, int *next);
int Index_KMP(char S[], char T[], int pos, int next[]);

int schoolKmpTest()
{
    char S[MAXSTRLEN+1],T[MAXSTRLEN+1];
    char S1[MAXSTRLEN],S2[MAXSTRLEN];
    cin >> S1 >> S2;
    strcpy(&S[1],S1);
    strcpy(&T[1],S2);
    S[0]=strlen(S1);
    T[0]=strlen(S2);
    int *next = new int[T[0]+1];
    get_next_val(T, next);
    cout<<Index_KMP(S,T,1,next);
    return 0;
}

/* 请在这里填写答案 */
