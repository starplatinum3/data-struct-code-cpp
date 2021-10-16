//1115 Counting Nodes in a BST (30 ·Ö)
#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
		int val;
		Node *l,*r;
		Node(int val): val(val) {
			l=r=nullptr;
		}

};

Node * ins(int x,Node *t) {
	if(t==nullptr) {
		t=new Node(x);

	} else {
		if(x<=t->val) {
			t->l=ins(x,t->l);
		} else if(x>t->val) {
			t->r=ins(x,t->r);
		}
	}
	return t;
}
pair<Node*,int>p;
const int MAX_NODE_CNT=1e3+6;
int cnt[MAX_NODE_CNT];
int maxLev=0;
void lev(Node *t) {
	queue<pair<Node*,int>>q;
	q.push(make_pair(t,0));
	while(!q.empty()) {
		auto fr=q.front();
		q.pop();
		int step=fr.second;
		Node * nod=fr.first;
		cnt[step]++;
		if(nod->l) {
			q.push(make_pair(nod->l,step+1));
		}
		if(nod->r) {
			q.push(make_pair(nod->r,step+1));
		}

		maxLev=max(maxLev,step);
	}
	printf("%d + %d = %d\n",cnt[maxLev],cnt[maxLev-1]
	       ,cnt[maxLev]+cnt[maxLev-1]);
}
int n;
int main() {
	cin>>n;
	Node *t=nullptr;
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d",&x);
		t=ins(x,t);
	}
	lev(t);
}
