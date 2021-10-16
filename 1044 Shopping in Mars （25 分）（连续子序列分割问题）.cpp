#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

//https://blog.csdn.net/weixin_41988545/article/details/83652018
//a

/*
int n,m;
int a[100005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int st = 0,en = 0;
    int sum = 0;
    int flag = 0;
    //map<int ,int > m;
    while(1)
    {
        while(en < n&&sum < m)
        {
            sum+=a[en++];
        }
        if(sum < m)break;
        while(sum > m)sum -=a[st++];
        if(sum == m)
        {printf("%d-%d\n",st+1,en);
        flag=1;
        sum -=a[st++];}
    }
    return 0;
}*/

void printArr(int * arr, int from , int to) {
	for(int i=from; i<to; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

// https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264
int main() {
	int n,m,sum[100005]= {0},temp,first = 0;
	int minn = 0x7f7f7f7f;
	bool isfind = false;
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&temp);
		sum[i] = sum[i-1]+temp;
		while(sum[i]-sum[first]>m) {
			minn = min(minn,sum[i]-sum[first]);
//        缩得再小也是大于m的
			first++;
		}
//		first i 只能往后移动 i 一直在first 后面 或者和他一样
		printf("first, i, %d,%d\n",first,i);
		printf("sum[i]-sum[first] %d\n",sum[i]-sum[first]);
		if(sum[i]-sum[first] == m) {
			printf("%d-%d\n",first+1,i);
			isfind = true;
		}
	}
	printf("min %d\n",minn);
	if(!isfind) {
		int j = 0;
//		如果凑不出刚刚好的 也要多花钱买
		for(int i = 1; i<=n; i++) {
			while(sum[i]-sum[j]>minn) {
				j++;
			}
//            为什么是 ==minn
			printf("i, j, %d,%d\n",i,j);
			printf("sum[i]-sum[j] %d\n",sum[i]-sum[j]);
            // minn 刚好比 要凑出来的数字 大一点
			if(sum[i]-sum[j]==minn) {
				printf("%d-%d\n",j+1,i);
			}
		}
	}
	return 0;
}
