#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N=122;
int a[N],b[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
		for(int i=0;i<n;i++){
		scanf("%d",b+i);
	}
	
	int ze=1;
	int idx=0;
	int j;
	for( j=0;b[j]<=b[j+1]&&j<n;j++){
//		if(b[j]==a[0]){
//			idx=j;
//			break;
//		}
//		if(b[j-1]>=b[j]){
//			ze=0;
//		}
	}
//	printf("j %d a[j] %d\n",j,a[j]);
	idx=j+2;
	j++;
	for(;a[j]==b[j]&&j<n;j++);
	if(j==n){
			printf("Insertion Sort\n");
//		sort(b,b+idx);
			sort(a,a+idx);
	}
//	
//	if(ze){
//		printf("Insertion Sort\n");
//		sort(b,b+idx);
//		
//	}
	else{
		printf("Merge Sort\n");
		int doit=1;
		int k=1;
		while(doit){
			doit=0;
			for(int i=0;i<n;i++){
				if(a[i]!=b[i]){
					doit=1;
				}
			}
			k*=2;
			for(int i=0;i<n/k;i++){
//				printf("i*k %d (i+1)*k %d\n",i*k,(i+1)*k);
				sort(a+i*k,a+(i+1)*k);
			}
			sort(a+(n/k)*k,a+n);
		}
	}
	
	int fir=1;
	
	for(int i=0;i<n;i++){
		if(fir)fir=0;
		else printf(" ");
		printf("%d",a[i]);
	}
}
