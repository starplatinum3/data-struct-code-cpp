//1125 Chain the Ropes (25 ��)

#include <bits/stdc++.h>
using namespace std;
int n;
//https://blog.csdn.net/blackneed/article/details/84765715
//priority_queue<double, vector<double>, greater<double> >q;
priority_queue<int, vector<int>, greater<int> >q;
//��С�ĳ��� 
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
//		���Ǹ�Ϊint�����ݾͿ����ˡ��Ҿ���������Ŀ��һ��ì��֮����

//https://blog.csdn.net/weixin_43590232/article/details/104327845
//		��С�� �ó��� ���ĵ� 
//		cout<<"fr se"<<fr<<" "<<se<"\n";
		q.push((fr+se)/2);
	}
	cout<<round(q.top())<<"\n";
}
