#include<bits/stdc++.h>
using namespace std;
const int MAX_N=20000+7;
const int INF=0x3f3f3f3f;
int n;
// a 
// 不是long long  的原因
long long a[MAX_N];
long long maxSubSum=-1,tmpMax=0;
int serI=0,serJ=0;
int tmpSI=0,tmpSJ=0;
// -10 1 2 3 4 -5 -23 3 7 -21
//     0  1 3 6 10 
//     0  1 3 6 0  0 3 10
//     0  1 3 6 0  0 3 10  0
// 应该是连在一起的序列吧 不然应该不能直接 0
// https://www.cnblogs.com/yi-ye-zhi-qiu/p/9508987.html
int main(){
    scanf("%d",&n);
    serJ=n-1;
//     要 n-1
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
        tmpMax+=a[i];
         if(tmpMax<0){
             tmpMax=0;
//              tmpMax=0;
//              serI=i+1;
//              serJ=i+1;
             tmpSI=i+1;
//              tmpSJ=i+1;
         }else{
//              tmpMax+=a[i];
//              serJ=i;
//              tmpSJ=i;
             if(tmpMax>maxSubSum){
                 maxSubSum=tmpMax;
                 serI=tmpSI;
                 serJ=i ;
               
             }
//              maxSubSum=max(tmpMax,maxSubSum);
         }
       
    }
//     这个放在for 外面
     if(maxSubSum<0)maxSubSum=0;
    printf("%lld %lld %lld\n",maxSubSum,a[serI], a[serJ]);
}
