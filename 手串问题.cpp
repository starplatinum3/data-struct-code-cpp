#include<iostream>
#include<cstring>
using namespace std;
int n,m,c,x,color; 
int a[10005][100],b[100];
// a数组记录珠子的颜色  a[2][1]=1:2号串珠上有1号颜色
// b数组记录某种颜色在哪个珠子出现 b[1]=2:1号颜色在2号串珠上出现
int main(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>n>>m>>c;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>color;
            a[i][color]=1;
            // i 串珠上有color 这种颜色
        }
    }
    int k=0,res=0;// res记录不符需求的颜色
    for(int j=1;j<=c;j++){ 	// 颜色
        for(int i=0;i<n;i++){
            // 所有的串珠
            // 有这种颜色
            if(a[i][j]==1){
                printf("====\n");
                printf("珠子序号 i %d , 颜色 j %d\n",i,j);
                // k 是新的颜色嘛
                printf("%d k\n",k);
                b[k++]=i+1; // 第j种颜色 出现在哪几个珠子上   
                // k表示颜色出现在珠子上的数量  i+1表示珠子编号
            }
        }
        if(k!=1){
            for(int i=0;i<k-1;i++){
            // b[i+1]-b[i]  表示同种颜色 珠子间隔是多少
            // 为啥是同种颜色呢
                if(b[i+1]-b[i]<m){
                    res++;
                    break;
                }
            }
        }
        k=0;// 遍历完一种颜色重新标记为0  
    }
    cout<<res<<endl;
    return 0;
}
