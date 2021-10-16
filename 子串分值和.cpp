//
// Created by Lenovo on 2021/2/10.
//

#include <bits/stdc++.h>
#define int long long
const int N = 1e6+7;
using namespace std;
string s;
int dp[N];
int pos[30];

signed main()
{
    cin>>s;
    for(int i = 0 ; i < 30 ; i ++){
        pos[i] = -1;
    }
    dp[0] = 1;
    pos[s[0]-'a'] = 0;
    for(int i = 1 ; i < s.size() ; i ++){
        dp[i] = dp[i-1]+i-pos[s[i]-'a'];
        pos[s[i]-'a'] = i;
        //cout<<dp[i]<<endl;
    }
    int res =0;
    for(int i = 0 ; i < s.size() ; i ++)
        res += dp[i];
    cout<<res<<endl;

    return 0;
}
