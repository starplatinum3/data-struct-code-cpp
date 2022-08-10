#include<iostream>
#include<algorithm>
#include<vector>

//https://blog.csdn.net/zhongxinyun/article/details/113796110
using namespace std;
vector<int> m;
int n;
int maxnum=-1;
bool judge(int k){
    int d=k;
    for(int i=0;i<n;i++){
        d=2*d-m[i];
//        比最高的还要高 
//3 4 3 2 4
//5 5+1 5+1+1 
//4 3 4
//4 4+1 自然比4 大，肯定能过了，如果后面的是5
//那么 4 3 5 
//5 >4  不符合要求 
        if(d>=maxnum)
            return true;
//            没有能量 
        if(d<0)
            return false;
    }
    return true;
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        m.push_back(t);
//        每个建筑物的高度 
//最高的建筑物的高度 
        maxnum=max(maxnum,t);
    }
    bool flag=false;
    int i;
    for(i=0;i<=maxnum;i++){
        if(judge(i))
        {
            flag=true;
            break;
        }
    }
    cout << i;
    return 0;
}

