#include <bits/stdc++.h>
using namespace std;
map<int,bool> mp;
//https://www.baidu.com/link?url=iVbqAs41z7290sx-2CAzlJlfzy33AxfoMhCPuUBXaxxAnr8MI6CuZyWCiOPUTWLkYSk03mxLDWOzKbgi50s2LnREfrnhEh1uyv27ldkM4l7&wd=&eqid=eb322d2d0000fb9600000005603f9c19
int main(){
	int m,n,u,v,a;
	cin>>m>>n;
	vector<int> pre(n);
	for (int i=0;i<n;i++){
		cin>>pre[i];
		mp[pre[i]]=true;
	}
	for (int i=0;i<m;i++)
	{
		cin>>u>>v;
		for (int j=0;j<n;j++)
		{
			a=pre[j];
//			点 夹在 u v 之间 
			if ((a>u&&a<v)||(a>v&&a<u)||(a==u)||(a==v))break;
		}
		if (mp[u]==false&&mp[v]==false)
			printf("ERROR: %d and %d are not found.\n",u,v);
		else if (mp[u] == false || mp[v] == false)
			printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
		else if (a == u || a == v)
			printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
		else
			printf("LCA of %d and %d is %d.\n", u, v, a);
	}
	return 0;
}
