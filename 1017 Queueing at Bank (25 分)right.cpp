#include<bits/stdc++.h>
using namespace std;
struct node{
    int s;
    int t;
}a[10005];//�ڵȴ������� 
node q[10005];//�ڰ�ҵ������� 
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
        a[i].s=h*3600+m*60+s;//��ʼ��ʱ�� 
        a[i].t=int(t*60);//��Ҫ����� 
        if(a[i].t>3600){//ÿ�������60���� 
            a[i].t=3600;
        } 
    }
    sort(a+1,a+n+1,cmp); 
    /*for(int i=1;i<=n;i++){
        cout<<a[i].s<<" "<<a[i].t<<endl;
    } */ 
    
    //��ʼ��
    double sum=0;//�ȴ�����ʱ�� 
    int p_sum=0;//���� 
    for(int i=1;i<=n;i++)
    {
        if(i<=k)
        {
//        	k ���� 
            p_sum++;
            if(a[i].s<=28800){
                sum+=28800-a[i].s;
                //cout<<"��"<<a[i].s<<"��"<<"���� "<<28800-a[i].s<<endl;
                a[i].s = 28800;
            }
            q[i].t=a[i].t;
            q[i].s=a[i].s;            
        }else{
            q[i].s=999999;
        }
     } 
     
     int p=k+1;//p������һ���ֵ�˭�� 
     int mint=999999;
     while(p<=n){//�������ڵ��Ű�ҵ�� 
         if(a[p].s>61200) {//����17���� 
             break; 
         }
         //���������н���ʱ�������ʱ��mint 
//         ���ڵ� ��������� 
        int mint=999999;
        for(int i=1;i<=k;i++){
            if(q[i].s+q[i].t<mint)
            {
                mint=q[i].s+q[i].t;
            }
        } 
        //cout<<"mint "<<mint<<endl;        
        //����mint��һʱ��
        for(int i=1;i<=k;i++){
            if(q[i].s+q[i].t==mint){
                //��qi���˻��ɵ�p���� 
                q[i].s=a[p].s;
                q[i].t=a[p++].t;
                p_sum++;
//              mint  ǰ��Ľ���ʱ�� ���Ǻ���Ŀ�ʼʱ�� 
// ���� �����������ʼ ʱ�� ˵��������˻��õȻ� 
                if(mint>q[i].s){
//                	������˵��˻� 
                    sum+=mint-q[i].s;
                    //cout<<"��"<<q[i].s<<"��"<<"���� "<<mint-q[i].s<<endl;
                    q[i].s=mint;//����˵Ŀ�ʼʱ�䲻����ԭ������ 
//                    ���ڵĽ�����, ������˸����� 
                }
            }        
        } 
     } 
     if(p_sum!=0){ 
         sum=sum/p_sum;
         sum=sum/60;    
    }
    else{//���������
        sum=0;
    }
     printf("%.1lf\n",sum);
     return 0;
 }
