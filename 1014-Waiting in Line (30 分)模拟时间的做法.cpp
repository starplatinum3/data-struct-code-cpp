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
//1014-Waiting in Line (30 ��)ģ��ʱ�������
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
    for(int i=0;i<n*m&&time.size();i++){//����������ȰѶ����� ��Ȼ�������
        queues[idx].push(time.front());
        time.pop();
        idx++;
        idx%=n;
    }
    int rec[1010]={0};
    for(int i=0;i<1010;i++){
        rec[i]=-1;
    }
    for(int i=1;i<=540;i++){//һ��һ�ֵ�ģ�� ģ�⵽����5��
        for(int j=0;j<n;j++){
            if(queues[j].size()==0){
                continue;
            }
//            ���ﲻ�ð� queue ��������ж�spend--��  
            queues[j].front().isServed=1;
            queues[j].front().spend--;
//            �����Ļ� 2 ���� ����Ϊfr ֻ��-1 �����Բ�����0��
//Ŷ ��֪���� ֻ����ǰ����ڹ�̨���� ����ֻ����ǰ���-- ��  
            if(queues[j].front().spend==0){
                people tmp=queues[j].front();
                queues[j].pop();
                rec[tmp.no]=i;
            }
        }
        int flag=1;
        while(flag){//���½����˵Ķ���
            flag=0;
            int minsize=999999999,idx1=0;
            for(int j=0;j<n;j++){
//            	M (��10, the maximum capacity of each line inside the yellow line), 
                if(queues[j].size()<minsize&&queues[j].size()<m){
                    minsize=queues[j].size();
                    idx1=j;
                    flag=1;
                }
            }
//            ���ҵ��յ� 
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
//    �����Ŷ� �����Ѿ��ڽ��ܷ���� 
    for(int i=0;i<n;i++){//����Ǵ���ע���1��
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


