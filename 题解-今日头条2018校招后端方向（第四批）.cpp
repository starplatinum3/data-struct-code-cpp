//���-����ͷ��2018У�к�˷��򣨵�������

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int count[50005];
int n,m;
int ans=0;
 
//��鵱ǰ���䳤��(step)�Ƿ����� m ��������ʵ��ȫ a �� ȫ b 
bool func(int step){
    for(int i=0;i+step<n;i++){
//    	�������� m  
//    	(count[i+step]-count[i-1]) a �ĸ��� 
        if(m>=step+1-(count[i+step]-count[i-1]))return true;
			//��� a  ��ʽ m>=������ b �ĸ��� 
		if(m>=count[i+step]-count[i-1])return true;	
		//��� b  ��ʽ�� m>=������ a �ĸ��� 
    }
    return false;
}
 
 
int main(){
    cin>>n>>m;
    string str;
    cin>>str;
    //���벢����� count ���� 
    int sum=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='a')count[i]=++sum;
        else count[i]=sum;
    }
 
    //���������������ֵ 
	int l=0,r=n-1,mid; 
    while(l<r){
//    	���Ծ����� 
        mid=l+(r-l)/2;
        if(func(mid)){
            l=mid+1;
        }else r=mid;
    }
    ans=max(ans,l);
     
    cout<<ans<<endl;
    return 0;
     
}
