//1128 N Queens Puzzle (20 ·Ö)
#include<cstdio>
#include<algorithm>
#include<vector>
//a

using namespace std;

int che(vector<int>a){
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]==a[j]||a[j]-a[i]==j-i){
				return 0;
			}
		}
	}
	return 1;
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		vector<int>a;
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			a.push_back(x);
		}
		if(che(a)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
} 
