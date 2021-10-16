#include<bits/stdc++.h>
using namespace std;
vector<int>q;
// https://blog.csdn.net/qq_38570571/article/details/88649919
int v[10005]={0};//标记已被处理的数据
int dfs(int x){
	
	int sum=0; 
	int k=0;
	for(int i=x;i<q.size();i++){
		// '|'
		if(q[i]==-1){
			sum=max(sum,dfs(i+1));
		}
        // '('
		if(q[i]==-2){
			k++;
            // 第几个（
			sum+=dfs(i+1);
		}
        // ）
		if(q[i]==0){
			k--;
            // 如果不存在（ 就会有 k==-1
			if(k==-1){
				return sum;
			}
		}
        // q 里还有数值
        // （）
        // 因为前面推过的  后面还会推过来，所以有过的就不要了
		if(k==0&&q[i]>0&&v[i]==0){
			v[i]=1;
			sum+=q[i];
		}
	}
	return sum;
	
	
	
}
int main(){
	string a;
	cin>>a;
	int sum=0;
	for(int i=0;i<=a.size();i++){
		if(a[i]=='x'){
			sum+=1;
		}else {
			if(sum!=0)
		    {
                // 不是x的话 就刷新一次了
                // printf("")
		    	q.push_back(sum);
		    	sum=0;
			}
		    
		    if(a[i]=='('){
		    	q.push_back(-2);
			}
			if(a[i]==')'){
				q.push_back(0);
			}
			if(a[i]=='|'){
				q.push_back(-1);
			}
		}
	} 
 
	cout<<dfs(0);
 
} 