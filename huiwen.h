//
// Created by Lenovo on 2021/1/25.
//

#ifndef DATASTRUCT_HUIWEN_H
#define DATASTRUCT_HUIWEN_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int dp[1001][1001];

int main()
{
    char ch1[1001];
    char ch2[1001];
    string s;
    while(cin>>s)
    {

        for(int i=0;i<s.length();i++)
        {
            ch1[i]=s[i];
            ch2[i]=s[s.length()-i-1];
        }
        int len = s.length();
        for(int i=1;i<=s.length();i++)
            for(int j=1;j<=s.length();j++)
            {
                if(ch1[i-1]==ch2[j-1])
                {
                    //记录回文串长
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    if(dp[i-1][j]>dp[i][j-1])dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                }


            }

        cout<<(len - dp[len][len])<<endl;
//        能变成回文串所需添加的最少字符数。

    }
    return 0;
}

//if(ch1[i-1]==ch2[j-1]){
//dp[i][j]=dp[i-1][j-1]+1
//
//}else{
//dp[i][j]=max(dp[i-1][j],dp[i][j-1])
//}


#endif //DATASTRUCT_HUIWEN_H
