//1089
#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
	int n;
	scanf("%d",&n);
	int origin[100],current[100];
	for(int i=0;i<n;++i)
		scanf("%d",&origin[i]);
	for(int i=0;i<n;++i)
		scanf("%d",&current[i]);
	int m=0;
	//check if it is a insertion sort
	while(current[m]<=current[m+1])
		++m;//check the sorted element
	int temp=++m;
//	前面 递增 12378 
//后面都一样 5 9 4 6 0 
	while(temp<n&&current[temp]==origin[temp])
		++temp;//check the uninserted element
	if(temp==n)
	{//Insertion Sort
		printf("Insertion Sort\n");
		sort(origin,origin+m+1);
	}
	else
	{//Merge Sort
		printf("Merge Sort\n");
		int k=1,flag=1;
		while(flag)
		{
			flag=0;
			//check if the origin sequence has been 
			//merged the same as current sequence
			for(int i=0;i<n;++i)
				if(origin[i]!=current[i])
					flag=1;
			k*=2;
			printf("k %d\n",k);
			for(int i=0;i<n/k;++i){
				printf("sort i*k %d (i+1)*k %d\n",i*k ,(i+1)*k);
				sort(origin+i*k,origin+(i+1)*k);
			}
				printf("sort (n/k)*k %d n %d\n",(n/k)*k ,n);
				
			sort(origin+(n/k)*k,origin+n);
		}
	}
	for(int i=0;i<n;++i)
	{
		if(i!=0)
			printf(" ");
		printf("%d",origin[i]);
	}
	return 0;
}
