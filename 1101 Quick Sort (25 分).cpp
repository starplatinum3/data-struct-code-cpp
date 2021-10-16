#include<bits/stdc++.h>
//1101 Quick Sort (25 ·Ö)
//https://pintia.cn/problem-sets/994805342720868352/problems/994805366343188480
//ÕýÈ· 
using namespace std;
const int MAX_N=100007;
int a[MAX_N],b[MAX_N],c[MAX_N];
int INF=0x3f3f3f3f;
vector<int>ans;
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int Max=0;
       for(int i=0;i<n;i++){
        if(Max<a[i]){
            Max=a[i];
            b[i]=1;
        }
    }
    int Min=INF;
      for(int i=n-1;i>=0;i--){
        if(Min>a[i]){
            Min=a[i];
            c[i]=1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(b[i]&&c[i])
           ans.push_back(a[i]);
    }
    printf("%d\n",ans.size());
    int fir=1;
    for(auto val:ans){
        if(fir)fir=0;
        else printf(" ");
        printf("%d",val);
    }
    if(ans.size()==0){
        printf("\n");
    }
}
