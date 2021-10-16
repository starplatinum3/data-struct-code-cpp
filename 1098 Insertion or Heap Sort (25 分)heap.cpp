
#include<bits/stdc++.h>
///
using namespace std;
int n;
const int N=111;
int a[N],b[N];
void printA() {
	int fir=1;
	for(int i=0; i<n; i++) {
		if(fir)fir=0;
		else printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}

void printB() {
	int fir=1;
	for(int i=1; i<=n; i++) {
		if(fir)fir=0;
		else printf(" ");
		printf("%d",b[i]);
	}
	printf("\n");
}


void addjustDown(int r,int n) {
	int child=r*2;
	int val=b[r];
	while(child<=n) {
		if(child<n&&b[child]<b[child+1]) {
			child++;
		}
		if(val<b[child])break;
		b[child/2]=b[child];
	}
	b[child/2]=val;
}

void adjustDown(int low ,int high){
	int i=low;
	int j=i*2;
	while(j<=high){
		if(j<high&&b[j]<b[j+1])j++;
		if(b[j]>b[i]){
//			大顶堆 
			
//			儿子大于 爹 
//让爹 变大 
//printf("j %d  i %d\n",j,i); 
			swap(b[i],b[j]);
//			j=i;
			i=j;
			j=i*2;
		}else break;
	}
}


void adjustDown(int low,int high){
	int i=low;
	int j=i*2;
	while(j<=high){
		if(j+1<=high&&b[j]<b[j+1])j++;
//		i 前面 j 后面 小于 大顶堆 
		if(b[i]<b[j]){
			swap(b[i],b[j]);
			i=j;
			j=i*2;
//			j 类似 上面的初始化 
		}else break;
	}
}
//ac

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
	}
	int j=2;
	for(; j<=n&&b[j-1]<=b[j]; j++);

	int idx=j;
	j++;
//	printf("j %d b[j] %d\n",j,b[j]);
//	printf("idx %d b[idx] %d\n",idx,b[idx]);
//	printf("a[j] %d b[j]  %d\n",a[j], b[j]);
	for(; j<=n&&a[j]==b[j]; j++);
//	printf("j %d\n",j);
	if(j==n+1) {
		printf("Insertion Sort\n");
		sort(b+1,b+idx+1);
		printB();
	} else {
		printf("Heap Sort\n");
		int i;
		for( i=n;b[i]>=b[1];i--); 
//		printf(" swap b[1] %d  b[i] %d i %d \n",b[1],b[i],i);
		swap(b[1],b[i]);
		adjustDown(1,i-1);
		printB();
	}
}
