#include<iostream>
#include<cstring>
using namespace std;
int n,m,c,x,color; 
int a[10005][100],b[100];
// a�����¼���ӵ���ɫ  a[2][1]=1:2�Ŵ�������1����ɫ
// b�����¼ĳ����ɫ���ĸ����ӳ��� b[1]=2:1����ɫ��2�Ŵ����ϳ���
int main(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>n>>m>>c;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<x;j++){
            cin>>color;
            a[i][color]=1;
            // i ��������color ������ɫ
        }
    }
    int k=0,res=0;// res��¼�����������ɫ
    for(int j=1;j<=c;j++){ 	// ��ɫ
        for(int i=0;i<n;i++){
            // ���еĴ���
            // ��������ɫ
            if(a[i][j]==1){
                printf("====\n");
                printf("������� i %d , ��ɫ j %d\n",i,j);
                // k ���µ���ɫ��
                printf("%d k\n",k);
                b[k++]=i+1; // ��j����ɫ �������ļ���������   
                // k��ʾ��ɫ�����������ϵ�����  i+1��ʾ���ӱ��
            }
        }
        if(k!=1){
            for(int i=0;i<k-1;i++){
            // b[i+1]-b[i]  ��ʾͬ����ɫ ���Ӽ���Ƕ���
            // Ϊɶ��ͬ����ɫ��
                if(b[i+1]-b[i]<m){
                    res++;
                    break;
                }
            }
        }
        k=0;// ������һ����ɫ���±��Ϊ0  
    }
    cout<<res<<endl;
    return 0;
}
