#include "iostream"
#include "vector"
#include "string"
//1130 Infix Expression (25 ·Ö)
using namespace std;
struct node
{
	string val;
	int left,right;
};
vector<node> tree;
vector<bool> visit;
int root=1;
string dfs(int index){
	if (index==-1)return "";
	if (tree[index].right!=-1)
	{
		tree[index].val=dfs(tree[index].left)+tree[index].val+dfs(tree[index].right);
		if (index!=root)
		{
			tree[index].val="("+tree[index].val+")";
		}
	}
	return tree[index].val;
}
int main(){
	int n;
	cin>>n;
	tree.resize(n+1);
	visit.resize(n+1);
	for (int i=1;i<=n;i++){
		cin>>tree[i].val>>tree[i].left>>tree[i].right;
		if (tree[i].left!=-1)visit[tree[i].left]=true;
		if (tree[i].right!=-1)visit[tree[i].right]=true;
	}
	for (int i=1;i<=n;i++)
		if (visit[i]==false)
			root=i;
	cout<<dfs(root)<<endl;
	return 0;
}
