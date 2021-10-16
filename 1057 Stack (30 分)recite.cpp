//1057 Stack (30 分)
//a 
#include<bits/stdc++.h>
using namespace std;
vector<int>st;
//stack<int>st;
int n;
const int MAX_CNT=1e5+8;
const int N=1e5+8;
int bit[MAX_CNT];
int c[MAX_CNT];
int lowbit(int x){
	return x&(-x);
}
//void add(int x,int idx){
//	for(;idx<MAX_CNT;idx+=lowbit(idx)){
//		bit[idx]+=x;
//	}
//}
//
//int sum(int idx){
//	int res=0;
//	for(;idx>0;idx-=lowbit(idx)){
//		res+=bit[idx];
//	}
//	return res;
//}

//不是 sum 函数的关系 
void update(int x,int val){
   for(int i=x;i<N;i+= (i &-i))
       c[i]+=val;
}
int sum(int x){
   int res= 0;
   for(int i=x;i;i-=(i&-i))res+=c[i];
   return res;
}
//————————————————
//版权声明：本文为CSDN博主「resonbility」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/dotaerac/article/details/84349186

int get(int idx){
	int l=0,r=MAX_CNT;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
//		>=
		if(sum(mid)>=idx){
//			sum 太大 希望变小 那么右边界往左移 
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	return ans;
}

//
//int get(int x){
//   int l =0;  int r= N;
//   int ans;
//   while(l<=r){
//       int mid =(l+r)>>1;
//       if(sum(mid) >=x){
//           ans = mid;
//           r = mid-1;
//       }
//       else l=mid+1;
//   }
//   return ans;
//}

//————————————————
//版权声明：本文为CSDN博主「resonbility」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/dotaerac/article/details/84349186
//

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string op;
		cin>>op;
		if(op=="Pop"){
			if(st.empty()){
				cout<<"Invalid\n";
			}else{
				cout<<st.back()<<"\n";
//				add(-1,st.back());
					update(st.back(),-1);
				st.pop_back();
				
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
//			add(1,val);
				update(val,1);
			st.push_back(val);
		}
	}
	
}
