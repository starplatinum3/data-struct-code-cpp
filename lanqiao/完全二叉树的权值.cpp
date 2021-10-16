#include<bits/stdc++.h> 
using namespace std;
int tree[100001]; 
int sum[17]={0};
// https://blog.csdn.net/sueong/article/details/109122993
int main(){
	int n;
	cin>>n;
	int c=0;
	int deep=0;
	while(c<n){
		deep++;
		c+=pow(2.0,(deep-1));
		
	}
	for(int i=1;i<=n;i++)
	{
		cin>>tree[i];
	}
	int maxdeep=1;
	int max=-100000;//一定要将max初始为<= -100000 因为题目要求最小是这个 且题目会有负数
	for(int i=1;i<=deep;i++){//层号 
		 for(int j=pow(2.0,i-1);j<pow(2.0,i)&&j<=n;j++){//j是每个节点的下标 每层节点的范围是2^(i-1)--2^i-1从每层第一个数开始 ，如第二层第一个编号2 2^1 三层第一个编号4 2^2  （层号-1）^2
		          sum[i]+=tree[j];
		        }
				   
		if(sum[i]>max) //必须大于 不是大于等于 因为这样即使权值同 层数也是小的层数不会更新 
		{
			max=sum[i];
			maxdeep=i;
		}
		
	}
	cout<<maxdeep;
	return 0; 
	 
}
