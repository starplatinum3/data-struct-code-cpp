#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
//1014-Waiting in Line (30 分)模拟时间的做法
typedef long long ll;
struct people{
    int no,spend,isServed;
    people(){}
    people(int _no,int _spend){
        no=_no;
        spend=_spend;
        isServed=0;
    }
};
int main(){
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    queue<people> time;
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        time.push(people(i,tmp));
    }
    queue<people> queues[30];
    int idx=0;
    for(int i=0;i<n*m&&time.size();i++){//这个过程是先把队填满 当然可能填不满
        queues[idx].push(time.front());
        time.pop();
        idx++;
        idx%=n;
    }
    int rec[1010]={0};
    for(int i=0;i<1010;i++){
        rec[i]=-1;
    }
    for(int i=1;i<=540;i++){//一分一分的模拟 模拟到下午5点
        for(int j=0;j<n;j++){
            if(queues[j].size()==0){
                continue;
            }
//            这里不用把 queue 里面的所有都spend--吗  
            queues[j].front().isServed=1;
            queues[j].front().spend--;
//            这样的话 2 到了 ，因为fr 只是-1 ，所以不会是0的
//哦 我知道了 只有最前面的在柜台操作 所以只有最前面的-- 啊  
            if(queues[j].front().spend==0){
                people tmp=queues[j].front();
                queues[j].pop();
                rec[tmp.no]=i;
            }
        }
        int flag=1;
        while(flag){//找新进入人的队列
            flag=0;
            int minsize=999999999,idx1=0;
            for(int j=0;j<n;j++){
//            	M (≤10, the maximum capacity of each line inside the yellow line), 
                if(queues[j].size()<minsize&&queues[j].size()<m){
                    minsize=queues[j].size();
                    idx1=j;
                    flag=1;
                }
            }
//            能找到空地 
            if(flag){
                if(time.size()){
                    queues[idx1].push(time.front());
                    time.pop();
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
    }
//    还在排队 但是已经在接受服务的 
    for(int i=0;i<n;i++){//这就是处理注意点1的
        if(queues[i].front().isServed){
            rec[queues[i].front().no]=540+queues[i].front().spend;
        }
    }
    for(int i=0;i<q;i++){
        int tmp;
        cin>>tmp;
        tmp--;
        if(rec[tmp]==-1){
            cout<<"Sorry"<<endl;
        }
        else{
            int all=480+rec[tmp];
            printf("%02d:%02d\n",all/60,all%60);
        }
    }
    return 0;
}


