#include<cstdio>
#include<algorithm>
#define N 100001
using namespace std;
int j,n,ans,a[N];
int main(){
	scanf("%d",&n);
	//�������� 
	for(int i=0 ;i<n ;i++) scanf("%d",&a[i]);
	
	sort(a,a+n);
	//���ݴ���  
	for(j=n-1,ans=1 ;j>=0 ;j--,ans++){
		printf("ans %d j %d a[j] %d\n",ans,j,a[j]);
		if(a[j]<=ans){
//			�ܵ��� С�� ������ 
			break;
		}
	}
	//��Ϊ���жϵ�<=���˳�ѭ������˴���ǰһ��  
	printf("%d\n",ans-1);
	
	return 0;
} 

