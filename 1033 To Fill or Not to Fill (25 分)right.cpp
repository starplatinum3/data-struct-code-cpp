#include<bits/stdc++.h>
using namespace std;
struct sta{
    double p,d;
}a[505];
bool cmp(sta x,sta y){
    return x.d<y.d;
}
double cm,dist,davg;
//dist Ŀ�ĵ� 
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
//���� 
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
        //�������ܵ����ȫ��վ��
        for(int i=k+1;i<=n;i++){
//        	������  ������� 
             if(a[i].d>kd+m_range || a[i].d>=dist){
                 break;
             }
            //һ�������м۸�����˵ľ�ֹͣ 
            if(a[i].p<kp){
                nk=i;
                cheap=1;
                break;
            }
            //������һ���۸���Ա��˵�
            if(!can_get&&a[i].p<cheapest){
                cheapest=a[i].p;
                nk=i;
            }     
        } 
        //cout<<nk<<" "<<a[nk].d<<endl; 
        if(nk==-1){//�Ѿ��ﵽ��Զ�� 
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
        //ֻҪ��nk���������˾���
        //cout<<"��"<<k<<"��"<<nk<<" ����:"<<a[nk].d-kd<<" ��ǰ����:"<<oil<<endl;
        if(!cheap){
//        	����������˵� 
            //cout<<"��ǰΪ��С�����,"; 
            if(oil<cm){
                min_p += kp*(cm-oil);
                oil=cm;
            }
            oil-=(a[nk].d-kd)/davg;
            //cout<<"����"<<(a[nk].d-kd)/davg<<" ��ʣ"<<oil<<endl; 
            
        }else{
//        	  if((oil<a[nk].d-kd)/davg){
// Ϊʲô ���� (oil<(a[nk].d-kd)/davg){
//���͵���ȥ��һ���ط����� 
            if((oil<a[nk].d-kd)/davg){
                //cout<<"���"<<(a[nk].d-kd)/davg-oil; 
//                ����  
                min_p += kp*((a[nk].d-kd)/davg-oil);
                oil=(a[nk].d-kd)/davg;
            }
            oil-=(a[nk].d-kd)/davg;
            //cout<<"����"<<(a[nk].d-kd)/davg<<" ��ʣ"<<oil<<endl; 
        }        
        k=nk;
        //cout<<endl;
    }
    return 0;
}
