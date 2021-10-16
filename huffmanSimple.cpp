//
// Created by Lenovo on 2020/12/23.
//
//https://zhuanlan.zhihu.com/p/200780172

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
int n;
priority_queue<int, vector<int>, greater<int> > q;
//默认最大堆，此处用greater改为最小堆;
int ans;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        int tmp; cin>>tmp;
        q.push(tmp);
    }
    while(!q.empty()){
        int t1=q.top();
        q.pop();
        if(!q.empty()){
            int t2 = q.top();
            q.pop();
            int t3 = t1+t2;
            ans += t3;
            q.push(t3);
        }
    }
    cout<<ans<<endl;
    return 0;

}