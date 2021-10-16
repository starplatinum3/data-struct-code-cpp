//1057 Stack (30 ·Ö)
//not right
#include<bits/stdc++.h>
using namespace std;
//vector<int>st;
stack<int>st;
int n;
const int MAX_CNT=1e5+8;
int bit[MAX_CNT];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int idx){
	for(;idx<MAX_CNT;idx+=lowbit(idx)){
		bit[idx]+=x;
	}
}

int sum(int idx){
	int res=0;
	for(;idx>0;idx-=lowbit(idx)){
		res+=bit[idx];
	}
	return res;
}

int get(int idx){
	int l=0,r=MAX_CNT;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(sum(mid)<=idx){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string op;
		cin>>op;
		if(op=="Pop"){
			if(st.empty()){
				cout<<"Invalid\n";
			}else{
				cout<<st.top()<<"\n";
				add(-1,st.top());
				st.pop();
				
			}
		}else if(op=="PeekMedian"){
				if(st.empty()){
				cout<<"Invalid\n";
			}else{
				int len=st.size();
				int ans=get((len+1)/2);
				cout<<ans<<"\n";
			}
		}else if(op=="Push"){
			int val;
			cin>>val;
			add(1,val);
			st.push(val);
		}
	}
	
}
