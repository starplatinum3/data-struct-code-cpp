/*
第一步：构建最小（大）堆
第二步： 向下（上）调整 O(log_2 n)
*/
#include<bits/stdc++.h>
///
using namespace std;
#define MAX 9
int a[MAX+1] = {0,5,3,1,7,4,2,0,6,8}; //后9个数排序
void swap(int x, int y) {
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}
void adjustDown(int r, int n) {
	int child = 2*r;
	int val = a[r];
	while(child <= n) {
		if(child < n && a[child] > a[child+1])
			child++;//选取孩子较小的那个
		if(val < a[child]) break; //若父节点最小，则不需要调整
		a[child/2] = a[child];
//		小的到爸爸那里 
		child *= 2; //到下一层
	}
	a[child/2] = val;
}
int main() {
//	/建最小堆/

//建堆：0 3 1 6 4 2 5 7 8
//排序：0 1 2 3 4 5 6 7 8
	for(int i = MAX/2; i > 0; i--) { //从第一个非叶子节点开始
		adjustDown(i, MAX);
	}
	cout<<"建堆：";
	for(int i=1; i<=MAX; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
//		    /排序/
	for(int i = MAX; i > 1; i--) {
		swap(1,i);
		adjustDown(1,i-1);
	}
	cout<<"排序：";
	for(int i = MAX; i > 0; i--) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
