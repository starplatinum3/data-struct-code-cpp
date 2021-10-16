//
// Created by Lenovo on 2021/1/7.
//
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void mostClose(){
    int n,x;
    vector<int>v;
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        v.emplace_back(val);
    }
   auto it= lower_bound(v.begin(),v.end(),x);
    cout<<*it;
}