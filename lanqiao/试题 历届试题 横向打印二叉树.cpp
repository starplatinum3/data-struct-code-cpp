#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#define INF 0x3f3f3f3f
#define zero 1e-7

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll max_n=105;

char mp[max_n][max_n];//记录数字前面的'.'，'|' 和'-'
int a[max_n]={0};//记录输入的数字
int L[max_n]={0};//记录节点的左子树
int R[max_n]={0};//记录节点的右子树
int pos[max_n]={0};//记录节点的列号
int len[max_n]={0};//记录数字的长度

//添加新节点
void add(int r, int x) {
    if(x<r) {//若x<r则将x交给r的左子树处理
        if(!L[r]) {//若r的左子树为空，则将x放入这个位置
            L[r]=x;
            pos[x]=pos[r]+len[r]+3;//x的列号，3是"-|-"的长度
        }
        else {
            add(L[r], x);
        }
    }
    else {//否则将x交给r的左子树处理
        if(!R[r]) {
            R[r]=x;
            pos[x]=pos[r]+len[r]+3;
        }
        else {
            add(R[r], x);
        }
    }
}

#include "strUtil/strUtil.h"
int main() {
    int k=0;//k记录输入数字的个数
    int root;//记录根节点的值

    string s;
    getline(cin, s);
    cout<<"s:"<<s<<"\n";
    std::vector<std::string> splitStrs = split(s, ' ');
    for (const auto &val:splitStrs) {
        a[k++] = stoi(val);
    }
    for (int l = 0; l < k; ++l) {
        int temp = a[l];
        while (temp) {//计算数字a[k]的长度
            len[a[l]]++;
            temp /= 10;
        }
        if (!l) {//第一个输入的数字是根节点
            root = a[l];
            pos[a[l]] = 0;
        } else {
            add(root, a[l]);
        }

    }

//    while(cin>>a[k]) {
//        int temp=a[k];
//        while(temp) {//计算数字a[k]的长度
//            len[a[k]]++;
//            temp/=10;
//        }
//        if(!k) {//第一个输入的数字是根节点
//            root=a[k];
//            pos[a[k]]=0;
//        }
//        else {
//            add(root, a[k]);
//        }
//        k++;
//    }


    sort(a, a+k, greater<int>());//按降序排列，由排序二叉树的特性可知，自顶往下数值越小
    //这个循环是将每行的数字前面填满'.'，'|'和'-'
    for(int i=0; i<k; i++) {
        int j;
//                因为 还有个 |- ,所以-2
        for(j=0; j<pos[a[i]]-2; j++) {
            mp[i][j]='.';
//            mp[i][j]=' ';
            //            putchar(' ');
//            这里改成 ‘ ’ 自己也可以用了
        }
        mp[i][j++]='|';
        mp[i][j]='-';
    }
    //这个循环是处理每个节点从其右子树到左子树的纵向之间的'|'
    for(int i=0; i<k; i++) {
        int temp=pos[a[i]]+len[a[i]]+1;//这是节点a[k]右边的'|'的列号
        if(R[a[i]]) {//若该节点有右子树
//            ..|(i-2)....|-8-|
//            ..|(i-1)........|-7
//            5-|
// i-1
            for(int j=i-1; ; j--) {//往上
                if(a[j]>=R[a[i]]) break;
//                假如碰到了 10，就停止
                mp[j][temp]='|';
            }
        }
        if(L[a[i]]) {//若该节点有左子树
            for(int j=i+1; ; j++) {//往下
                if(a[j]<=L[a[i]]) break;
                mp[j][temp]='|';
            }
        }
    }
    for(int i=0; i<k; i++) {//打印输出
        for(int j=0; j<pos[a[i]]; j++)
            cout<<mp[i][j];
        cout<<a[i];
        if(L[a[i]] || R[a[i]]) cout<<"-|";
        //        有左子树或者有右子树
        cout<<endl;
    }
    return 0;
}
//https://www.cnblogs.com/wwqzbl/p/13578271.html
