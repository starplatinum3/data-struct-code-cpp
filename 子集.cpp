#include<stdio.h>
void oneTest();
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        oneTest();
    }
}

int max(int x,int y){
    if(x>y){
        return x;
    }
    return y;
}
void oneTest(){
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
  //   int a[n]=new int[n];
   // int b[n]=new int[n];
    int bigger=0;
    int smaller=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
         if(b[i]>a[i]){
             bigger++;
         }else if (b[i]<a[i]){
             smaller++;
         }
    }
    printf("%d\n",max(bigger,smaller));
    
}