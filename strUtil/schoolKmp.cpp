//
// Created by Lenovo on 2020/10/10.
//

//https://juejin.im/post/6844903655150190599
#include <cstring>
/**
 * 下标从0开始
 * @param T
 * @param next
 */
class KmpStart0{

    void get_nextval(char T[], int next[]){
        int i=2,j=0;
        next[0]=-1;
        next[1]=0;
        int m=strlen(T);
        while (i<=m){
            if(j==0||T[j]==T[i]){
                ++i;
                ++j;
                if(T[i]!=T[j])next[i]=j;
                else next[i]=next[j];
            }
            else j=next[j];
        }
    }

    int Index_KMP(char S[], char T[], int pos, int next[]){
        int j=0, i=pos,lens=strlen(S),lent=strlen(T);
        get_nextval(T,next);
        while (i<lens&&j<lent){
            if(S[i]==T[j]||j==-1){
                i++;
                j++;
            }
            else j=next[j];
        }
        if(j>=lent)return i-lent;
        else return -1;
    }

};

