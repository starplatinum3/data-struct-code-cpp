//1048 Find Coins (25 ��)
#include<bits/stdc++.h>
using namespace std;
 const int MAX_NUM=55555;
int n,m;
int cnt[MAX_NUM];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	int have=0;
	for(int num=1;num<=500;num++){
		if(cnt[num]&&cnt[m-num]){
			if(num<m-num){
				printf("%d %d\n",num,m-num);
			}else if(num==m-num){
				if(cnt[num]>=2){
						printf("%d %d\n",num,m-num);
				}else{
//					��� �ؼ� ��� �������� һ�� �����Ǹ���ֻ��һ��
 
					break;
				}
			}
			
			have=1;
			break;
		}
	}
	if(!have){
		printf("No Solution\n");
	}
}
