#include<bits/stdc++.h>
///
using namespace std;
const int N=9;
//int a[N]={421,31,3,13,1,24,14,12,31};
int a[N+1] = {0,5,3,1,7,4,2,0,6,8}; 
void adjustDown(int r,int n){
	int val=a[r];
	int child=r*2;
	while(child<=n){
		if(child<n&&a[child]>a[child+1]){
			child++;
		}
		if(val<a[child])break;
		a[child/2]=a[child];
		child*=2;
	}
	a[child/2]=val;
}

void printArr(int arr[],int from,int to){
	for(int i=from;i<to;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
//	下标从1 开始吗 
	for(int i=N/2;i>0;i--){
		adjustDown(i,N);
	}
//	0 3 1 6 4 2 5 7 8
	printArr(a,1,N+1);
	
}
