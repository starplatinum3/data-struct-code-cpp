#include<iostream> 
#include<cstdio> 
#include<algorithm>
//  https://blog.csdn.net/qq_24371627/article/details/108212564
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
int n,m,k; 
ll sum;
ll a[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    k = n+m+1;
    for(int i = 0;i<k;i++){
        scanf("%lld",&a[i]);
    }
    sum = 0;
    if(!m){
        for(int i = 0;i<k;i++){
            sum+=a[i];
        } 
        printf("%lld",sum);
        return 0;
    }
    else{
        // -1 2 3 4 5 6
        // -1 2 3
        //  4 5 6
        sort(a,a+k);
        sum-=a[0];sum+=a[k-1];
        for(int i = 1;i<k-1;i++){
            sum+=abs(a[i]);
        }
    }
    printf("%lld",sum);
    return 0;
}