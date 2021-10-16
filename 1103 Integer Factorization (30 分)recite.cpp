//1103 Integer Factorization (30 ·Ö)
#include<bits/stdc++.h>
using namespace std;

int n,m,p;
vector<int>pows;
void makePow(){
//	int tmp=pow(1,p);
		int tmp;
		pows.push_back(0);
	for(int i=1;tmp<=n;i++){
		tmp=pow(i,p);
		printf("index %d pow %d\n",i,tmp);
		pows.push_back(tmp);
		
		
	}
}
const int INF=0x3f3f3f3f;
int minSubSum=INF;
int maxSubSum=-INF;
vector<int>tmpSel,ans;
void dfs(int idx,int sumK,int sum,int subSum){
	if(sumK>m||sum>n){
		return;
	}
	if(sumK==m&&sum==n){
		if(subSum>maxSubSum){
			maxSubSum=subSum;
			ans=tmpSel;
		}
		return;
	}
	if(idx==0)return;
//   pows[idx]
	tmpSel.push_back(idx);
	dfs(idx,sumK+1,sum+pows[idx],subSum+idx); 
		tmpSel.pop_back();
			dfs(idx-1,sumK,sum,subSum); 
}
int main(){
 scanf("%d%d%d",&n,&m,&p);
 	makePow();
 	dfs(pows.size()-1,0,0,0);
 	if(ans.empty()){
 		printf("Impossible\n");
	 }else{
	 	printf("%d = ",n);
	 	int fir=1;
	 	for(int val:ans){
	 		if(fir){
	 			printf("%d^%d",val,p);
	 			fir=0;
			 }
	 		else {
	 			printf(" + %d^%d",val,p);
			 }
		 }
	 }
} 
