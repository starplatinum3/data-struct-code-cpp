#include <bits/stdc++.h>
using namespace std;
int n,i,k=1,a[200],b[200];
void perdown(int res[],int low,int high){
    int i=low,j=2*i;
    while(j<=high){
        if(j+1<=high&&res[j+1]>res[j])  j=j+1;
        if(res[j]>res[i]){
            swap(res[i],res[j]);
            i=j;
            j=2*i;
        }else break;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(i=2;i<=n;i++) if(b[i]<b[i-1]) break;
    for(int j=i;j<=n;j++) if(a[j]!=b[j]) k=0;
    if(k){
        cout<<"Insertion Sort"<<endl;
        sort(b+1,b+i+1);
    }else{
        cout<<"Heap Sort"<<endl;
        int i=n;
        while(b[i]>=b[1]) i--;
        printf("i %d\n",i);
        swap(b[1],b[i]);
        perdown(b,1,i-1);
    }
    for(int i=1;i<=n;i++) i!=1?cout<<' '<<b[i]:cout<<b[i];
    return 0;
}


