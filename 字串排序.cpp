//
// Created by Lenovo on 2021/2/10.
//

//https://blog.csdn.net/qq_43461168/article/details/109146495

// 打表可以过50%的数据
#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int N = 120;
char ans[1000];
int bit[N];
int n;
int flag;
int len;

int lowbit(int x){
    return x&(-x);
}
int add(int x,int val){
    while(x<N){
        bit[x] += val;
        x += lowbit(x);
    }
}
int sum(int x){
    int res = 0;
    while(x){
        res += bit[x];
        x -= lowbit(x);
    }
    return res;
}

void dfs(int pos,char par){
    if(flag) return;
    if(pos == len){
        int tmp = 0;
        ans[len] = 0;
        //cout<<ans<<endl;
        for(int i = 0 ; i < len ; i ++){
//        sum  1--x 的和，
            tmp += i-sum(ans[i]-'a'+1);
//            x位置加上 1 ，前面是下标啊
//就是变成另外一个字符吗
            add(ans[i]-'a'+1,1);
        }
        for(int i = 0 ; i < len ; i ++){
            add(ans[i]-'a'+1,-1);
        }
//        tmp 加起来是个什么
        if(tmp == n){
            flag = 1;
        }
        return;
    }
//    par 枚举的字符
    for(char now = par; now >= 'a' ; now --){
        ans[pos] = now;
        dfs(pos+1,now);
        if(flag) return;
    }
}

int main(){
    n = 1;
//    枚举n
    while(n <= 1000){
        flag = 0;
        for(len = 2; ; len ++){ // 枚举字符串长度
            for(char i = 'b';i <= 'a'+len-1;i ++){
                dfs(0,i);
                if(flag){
                    cout<<n<<": "<<ans<<endl;
                    break;
                }
            }
            if(flag) break;
        }
        n++;
    }
}


