//
// Created by Lenovo on 2021/1/7.
//

#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;
vector <vector <int> > vct;
//https://blog.csdn.net/qq_44443766/article/details/109829734
int change[4][2]={{0,0},{0,1},{1,1},{1,0}};
int s=1;//填充的数字1、2、3。。。
void divide(int n,int x,int y,int a,int b){
    //n（棋盘大小pow(2,n)*pow(2,n)）(x,y)特殊方格坐标，(a,b)所在方格左上角坐标
    if(n==1){
        for(int i=0;i<4;i++){
            if(a+change[i][0]!=x||b+change[i][1]!=y){
                vct[a+change[i][0]][b+change[i][1]]=s;
            }
        }
        s++;
        return ;
    }
    int xiang_x,xiang_y;//所在象限
    xiang_x=(x-a+1)/(pow(2,n-1)+1);
    xiang_y=(y-b+1)/(pow(2,n-1)+1);
    int zhong_x,zhong_y;//所在方格再次划分四小方格边界的左上角方格坐标
    zhong_x=a+pow(2,n-1)-1;
    zhong_y=b+pow(2,n-1)-1;
    for(int i=0;i<4;i++){
        if(xiang_x!=change[i][0]||xiang_y!=change[i][1]){
            vct[zhong_x+change[i][0]][zhong_y+change[i][1]]=s;
        }
    }
    s++;
    for(int i=0;i<4;i++){
        int next_x,next_y,next_a,next_b;
        if(xiang_x!=change[i][0]||xiang_y!=change[i][1]){
            next_x=zhong_x+change[i][0];
            next_y=zhong_y+change[i][1];
            next_a=a+change[i][0]*pow(2,n-1);
            next_b=b+change[i][1]*pow(2,n-1);
            divide(n-1,next_x,next_y,next_a,next_b);
        }
        else{
            next_x=x;
            next_y=y;
            next_a=a+xiang_x*pow(2,n-1);
            next_b=b+xiang_y*pow(2,n-1);
            divide(n-1,next_x,next_y,next_a,next_b);
        }
    }
}
int main(){
    int i,j,k;
    cin>>i>>j>>k;
    vct.resize(k+1);
    for(int n=0;n<vct.size();n++){
        vct[n].resize(k+1);
    }
    for(int q=1;q<=50;q++){
        if(pow(2,q)==k){
            k=q;
            break;
        }
    }
    divide(k,i,j,1,1);
    for(int m=1;m<=pow(2,k);m++){
        for(int n=1;n<=pow(2,k);n++){
            cout<<setiosflags(ios::right)<<setw(4)<<vct[m][n];
        }
        cout<<endl;
    }
    return 0;
}