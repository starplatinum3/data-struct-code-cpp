//1101 Quick Sort（25 分）
//https://blog.csdn.net/qq_38677814/article/details/81988212
#include <bits/stdc++.h>
using namespace std;
int a[102000];
bool b[102000];
bool c[102000];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int Max=0;
    for(int i=1;i<=n;i++){
//    	max 是之前的 max 只要他大于之前的就行 
        b[i]=(a[i]>Max);
        Max=max(Max,a[i]);
    }
    int Min=0x3f3f3f3f;
    for(int i=n;i>=1;i--){
        c[i]=(a[i]<Min);
        Min=min(Min,a[i]);  
    }
    vector <int> ans;
    for(int i=1;i<=n;i++){
        if(b[i]&&c[i]){
            ans.push_back(a[i]);
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    if(ans.size()==0){
        printf("\n");
    }
    return 0;
}
