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

//1056 Mice and Rice (25 分)
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
        int l=int(ceil(q.size()*1.0/m));//向上取整
        while(!q.empty()){            
            int mx=0;
            int k=-1;
            for(int i=1;i<=m;i++){//每m各一组
                if(!q.empty()){
                    x=q.front();
                    q.pop();
                    r[x]=l+1;//rank为组数+1
                    if(a[x]>mx){
                        mx=a[x];
                        k=x;
                    }
//                    最大的 
                }
            }
            p.push(k);//胜利者放入p
        }
//        不是唯一的胜利者 
        if(p.size()!=1){
            q=p;
//            q 是下次要比较的 
            queue<int>empty;
            swap(p,empty);
//            p 是下次的胜利者, 变成空的 
        }else{
//        	唯一的胜利者 
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
