//
// Created by Lenovo on 2021/2/21.
//

#include<cstdio>
#include<cstring>
#include<cmath>
#define MOD 1000000007
#define LL long long
using namespace std;

struct Matrix{
    LL v[6][6];
    Matrix(){memset(v,0,sizeof(v));}
};

Matrix mul(Matrix x ,Matrix y){
    Matrix ans;
    for(int i=0 ;i<6 ;i++){
        for(int j=0 ;j<6 ;j++){
            for(int k=0 ;k<6 ;k++){
                ans.v[i][j] = (ans.v[i][j] + x.v[i][k]*y.v[k][j])%MOD;
            }
        }
    }
    return ans;
}

Matrix q_pow(Matrix x,int k){
    Matrix ans;
    for(int i=0 ;i<6 ;i++) ans.v[i][i] = 1;
    while(k){
        if(k&1) ans = mul(ans,x);
        x = mul(x,x);
        k >>= 1;
    }
    return ans;
}

int n,m,a,b;;

int main(){
    //初始化
    Matrix T,ans;
    for(int i=0 ;i<6 ;i++){
        for(int j=0 ;j<6 ;j++){
            T.v[i][j] = 1;
        }
    }
    //数据输入
    scanf("%d%d",&n,&m);
    for(int i=0 ;i<m ;i++){
        scanf("%d%d",&a,&b);
        T.v[a-1][b-1] = 0; T.v[b-1][a-1] = 0;
    }
    //数据处理
    ans = q_pow(T,n-1);

    int sum = 0;
    for(int i=0 ;i<6 ;i++){
        for(int j=0 ;j<6 ;j++){
            sum = (sum+ans.v[i][j])%MOD;
        }
    }
    //结果输出
    printf("%d\n",(sum*((int)pow(4,n))%MOD)%MOD);

    return 0;
}