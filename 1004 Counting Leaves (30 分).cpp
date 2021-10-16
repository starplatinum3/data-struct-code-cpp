#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int level[100] = { 0 }, n, m, maxD = 0;
vector<vector<int>>tree;
vector<int>ans;
//https://blog.csdn.net/qq_37613112/article/details/90577948
//https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
void printQ(queue<int>q){
	for(auto val:q){
	 cout<<val<<", ";
	}
	putchar('\n');
} 
void f(int start) {
	queue < int>q;
	int last = start;
	int cnt = 0;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		//һ���ж��ٸ� û��С�� cnt 
		if (tree[temp].size() == 0)cnt++;
//		����һ��Ҷ�� 
		for (int i = 0; i < tree[temp].size(); i++)q.push(tree[temp][i]);
//		last ÿһ������һ�� 
printQ();
		if (temp == last) {
			printf("temp : %d, last :%d\n",temp,last);
			last = q.back();
			printf("last ���� :%d\n",last);
			ans.push_back(cnt);
			printf("cnt ����=0\n");
			cnt = 0;
		}
		q.pop();
	}
}
int main() {
	cin >> n >> m;
	tree.resize(100);
	for (int i = 0; i < m; i++) {
		int id, num;
		cin >> id >> num;
		for (int j = 0; j < num; j++) {
			int d;
			cin >> d;
			tree[id].push_back(d);
		}
	}
	f(1);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i == ans.size() - 1)cout << endl;
		else
			cout << " ";
	}
	return 0;
}

