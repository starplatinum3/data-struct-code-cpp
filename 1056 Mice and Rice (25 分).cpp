#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

//1056 Mice and Rice (25 ��)
queue<int>q,p;
int n,m,x;
int a[1005];
int r[1005];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        q.push(x);
    }
    while(1){
        int l=int(ceil(q.size()*1.0/m));//����ȡ��
        while(!q.empty()){            
            int mx=0;
            int k=-1;
            for(int i=1;i<=m;i++){//ÿm��һ��
                if(!q.empty()){
                    x=q.front();
                    q.pop();
                    r[x]=l+1;//rankΪ����+1
                    if(a[x]>mx){
                        mx=a[x];
                        k=x;
                    }
//                    ���� 
                }
            }
            p.push(k);//ʤ���߷���p
        }
//        ����Ψһ��ʤ���� 
        if(p.size()!=1){
            q=p;
//            q ���´�Ҫ�Ƚϵ� 
            queue<int>empty;
            swap(p,empty);
//            p ���´ε�ʤ����, ��ɿյ� 
        }else{
//        	Ψһ��ʤ���� 
            r[p.front()]=1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<r[i];
        if(i!=n-1) cout<<" ";
    }
    return 0;
}
