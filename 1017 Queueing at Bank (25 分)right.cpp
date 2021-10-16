#include<bits/stdc++.h>
using namespace std;
struct node{
    int s;
    int t;
}a[10005];//在等待的人们 
node q[10005];//在办业务的人们 
bool cmp(node &x,node &y){
        return x.s<y.s;
}

//https://www.cnblogs.com/caiyishuai/p/11306203.html
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int h,m,s;
        double t;
        scanf("%2d:%2d:%2d %lf",&h,&m,&s,&t);
        a[i].s=h*3600+m*60+s;//开始的时刻 
        a[i].t=int(t*60);//需要花多久 
        if(a[i].t>3600){//每个人最多60分钟 
            a[i].t=3600;
        } 
    }
    sort(a+1,a+n+1,cmp); 
    /*for(int i=1;i<=n;i++){
        cout<<a[i].s<<" "<<a[i].t<<endl;
    } */ 
    
    //初始化
    double sum=0;//等待的总时间 
    int p_sum=0;//人数 
    for(int i=1;i<=n;i++)
    {
        if(i<=k)
        {
//        	k 窗户 
            p_sum++;
            if(a[i].s<=28800){
                sum+=28800-a[i].s;
                //cout<<"第"<<a[i].s<<"人"<<"等了 "<<28800-a[i].s<<endl;
                a[i].s = 28800;
            }
            q[i].t=a[i].t;
            q[i].s=a[i].s;            
        }else{
            q[i].s=999999;
        }
     } 
     
     int p=k+1;//p代表下一个轮到谁了 
     int mint=999999;
     while(p<=n){//还有人在等着办业务 
         if(a[p].s>61200) {//超过17点了 
             break; 
         }
         //挑出队列中结束时间最早的时刻mint 
//         窗口的 最早结束的 
        int mint=999999;
        for(int i=1;i<=k;i++){
            if(q[i].s+q[i].t<mint)
            {
                mint=q[i].s+q[i].t;
            }
        } 
        //cout<<"mint "<<mint<<endl;        
        //跳到mint这一时刻
        for(int i=1;i<=k;i++){
            if(q[i].s+q[i].t==mint){
                //第qi个人换成第p个人 
                q[i].s=a[p].s;
                q[i].t=a[p++].t;
                p_sum++;
//              mint  前面的结束时间 就是后面的开始时间 
// 大于 后面的真正开始 时间 说明后面的人还得等会 
                if(mint>q[i].s){
//                	后面的人等了会 
                    sum+=mint-q[i].s;
                    //cout<<"第"<<q[i].s<<"人"<<"等了 "<<mint-q[i].s<<endl;
                    q[i].s=mint;//这个人的开始时间不再是原来的了 
//                    窗口的结束了, 后面的人跟上来 
                }
            }        
        } 
     } 
     if(p_sum!=0){ 
         sum=sum/p_sum;
         sum=sum/60;    
    }
    else{//特殊情况！
        sum=0;
    }
     printf("%.1lf\n",sum);
     return 0;
 }
