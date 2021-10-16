#include<bits/stdc++.h>
using namespace std;
struct sta{
    double p,d;
}a[505];
bool cmp(sta x,sta y){
    return x.d<y.d;
}
double cm,dist,davg;
//dist 目的地 
int n;
int main(){
    cin>>cm>>dist>>davg>>n;
    for(int i=1;i<=n;i++){
//    	, the unit gas price p
//distance between this station and Hangzhou d
        cin>>a[i].p>>a[i].d;
    }
    sort(a+1,a+1+n,cmp);
    int k=1;
//    he average distance per unit 
//gas that the car can run;
//距离 
    double m_range = cm*davg;
    double max_d=0;
    double min_p=0;
    if(a[1].d!=0){
        printf("The maximum travel distance = %.2f",max_d);
        return 0;
    }
    int can_get,nk;
    double kd,kp,cheapest;
    double oil=0; 
    while(1){
        can_get=0;
        kd=a[k].d;
        kp=a[k].p;
        nk=-1;
        cheapest=999999;
        if(kd+m_range>=dist){
            can_get=1;
        }
        int cheap=0;
        //遍历所能到达的全部站点
        for(int i=k+1;i<=n;i++){
//        	够不到  超过最后 
             if(a[i].d>kd+m_range || a[i].d>=dist){
                 break;
             }
            //一旦发现有价格更便宜的就停止 
            if(a[i].p<kp){
                nk=i;
                cheap=1;
                break;
            }
            //否则找一个价格相对便宜的
            if(!can_get&&a[i].p<cheapest){
                cheapest=a[i].p;
                nk=i;
            }     
        } 
        //cout<<nk<<" "<<a[nk].d<<endl; 
        if(nk==-1){//已经达到最远了 
            if(can_get){
                if(oil<(dist-kd)/davg){
                    min_p += kp*((dist-kd)/davg-oil);
                }
                printf("%.2f",min_p);
            }else{
                max_d=kd+m_range;
                printf("The maximum travel distance = %.2f",max_d);
            }
            break;
        }
        //只要到nk的油量加了就行
        //cout<<"从"<<k<<"到"<<nk<<" 距离:"<<a[nk].d-kd<<" 当前油量:"<<oil<<endl;
        if(!cheap){
//        	现在是最便宜的 
            //cout<<"当前为最小点加满,"; 
            if(oil<cm){
                min_p += kp*(cm-oil);
                oil=cm;
            }
            oil-=(a[nk].d-kd)/davg;
            //cout<<"用了"<<(a[nk].d-kd)/davg<<" 还剩"<<oil<<endl; 
            
        }else{
//        	  if((oil<a[nk].d-kd)/davg){
// 为什么 不是 (oil<(a[nk].d-kd)/davg){
//加油到够去下一个地方就行 
            if((oil<a[nk].d-kd)/davg){
                //cout<<"需加"<<(a[nk].d-kd)/davg-oil; 
//                加油  
                min_p += kp*((a[nk].d-kd)/davg-oil);
                oil=(a[nk].d-kd)/davg;
            }
            oil-=(a[nk].d-kd)/davg;
            //cout<<"用了"<<(a[nk].d-kd)/davg<<" 还剩"<<oil<<endl; 
        }        
        k=nk;
        //cout<<endl;
    }
    return 0;
}
