//1125 Chain the Ropes (25 分)

#include <bits/stdc++.h>
using namespace std;
int n;
//https://blog.csdn.net/blackneed/article/details/84765715
//priority_queue<double, vector<double>, greater<double> >q;
priority_queue<int, vector<int>, greater<int> >q;
//最小的出来 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
//		double x;
				int x;
		cin>>x;
		q.push(x);
	}
	while(!q.empty()&&q.size()>=2){
//		double fr=q.top();
		int  fr=q.top();
		q.pop();
//		double se=q.top();
		int se=q.top();
		q.pop();
//		于是改为int型数据就可以了…我觉得这是题目的一个矛盾之处。

//https://blog.csdn.net/weixin_43590232/article/details/104327845
//		最小的 拿出来 消耗掉 
//		cout<<"fr se"<<fr<<" "<<se<"\n";
		q.push((fr+se)/2);
	}
	cout<<round(q.top())<<"\n";
}
