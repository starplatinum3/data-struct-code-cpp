//https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976

int n,m;
const int N=1e4+8;
int a[N];
int ma=0;
int dp[N];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=m;i>=0;i--){
		for(int j=0;j<=a[i];j++){
//			失去了这个数字 但是尝试另外一个 
			dp[i]=max(dp[i],dp[i-a[j]]+j);
		}
		ma=max(dp[i],ma);
	}
	
	
}

