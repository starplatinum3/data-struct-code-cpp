//1057 Stack (30 ��)
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

//���� sum �����Ĺ�ϵ 
void update(int x,int val){
   for(int i=x;i<N;i+= (i &-i))
       c[i]+=val;
}
int sum(int x){
   int res= 0;
   for(int i=x;i;i-=(i&-i))res+=c[i];
   return res;
}
//��������������������������������
//��Ȩ����������ΪCSDN������resonbility����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/dotaerac/article/details/84349186

int get(int idx){
	int l=0,r=MAX_CNT;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
//		>=
		if(sum(mid)>=idx){
//			sum ̫�� ϣ����С ��ô�ұ߽������� 
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

//��������������������������������
//��Ȩ����������ΪCSDN������resonbility����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/dotaerac/article/details/84349186
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
