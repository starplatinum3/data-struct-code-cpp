//1130 Infix Expression (25 ��)

#include<bits/stdc++.h>
using namespace std;


class Node {
	public:
		int l,r;
		string val;
		Node(int l, int r,string val):
			l(l),r(r),val(val) {
		}
		Node() {
		}
};
	int root;
int n;
const int MAX_NODE_CNT=222;
Node tr[MAX_NODE_CNT];
bool vis[MAX_NODE_CNT];


string dfs(int idx) {
	if(idx==-1) {
		return "";
	}
	if(tr[idx].r!=-1) {
		tr[idx].val=dfs(tr[idx].l)+tr[idx].val+dfs(tr[idx].r);
		if(idx!=root) {
			tr[idx].val="("+tr[idx].val+")";
		}
	}


	return 	tr[idx].val;

}


//string dfs(int index){
//	if (index==-1)return "";
//	if (tr[index].r!=-1)
//	{
//		tr[index].val=dfs(tr[index].l)+tr[index].val+dfs(tr[index].r);
//		if (index!=root)
//		{
//			tr[index].val="("+tr[index].val+")";
//		}
//	}
//	return tr[index].val;
//}
//��������������������������������
//��Ȩ����������ΪCSDN������ysq96����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/ysq96/article/details/81589738
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		string val;
		int l,r;
		cin>>val	>>l>>r;
		tr[i]=Node(l,r,val);
		if(l!=-1) {
			vis[l]=true;
		}
		if(r!=-1) {
			vis[r]=true;
		}
	}

	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			root=i;
		}
	}
	string ans=	dfs(root);
	cout<<ans;
}
