#include<cstdio>
#include<algorithm>
#define N 100001
using namespace std;
int j,n,ans,a[N];
int main(){
	scanf("%d",&n);
	//数据输入 
	for(int i=0 ;i<n ;i++) scanf("%d",&a[i]);
	
	sort(a,a+n);
	//数据处理  
	for(j=n-1,ans=1 ;j>=0 ;j--,ans++){
		printf("ans %d j %d a[j] %d\n",ans,j,a[j]);
		if(a[j]<=ans){
//			跑的量 小于 天数了 
			break;
		}
	}
	//因为当判断到<=才退出循环，因此答案是前一天  
	printf("%d\n",ans-1);
	
	return 0;
} 

