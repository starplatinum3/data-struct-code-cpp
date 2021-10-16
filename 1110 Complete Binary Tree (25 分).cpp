//1110 Complete Binary Tree (25 ·Ö)
#include<bits/stdc++.h>
using namespace std;


class Node {
	public:
		int l,r;
		int idx;
		int se;
		Node (int se,int l,int r) :se(se),l(l),r(r) {
			idx=0;
		}
		Node(){
		}
};
const int MAX_NODE_CNT=33;
Node tr[MAX_NODE_CNT];
int haveFa[MAX_NODE_CNT];
//Node* r
int n;
//void levNode(int  r) {
//
//	queue<Node*>q;
//	queue<Node*>q;
//	q.push();
//	while(!q.empty()) {
//		Node * fr=q.front();
//		q.pop();
//		if(tr[fr->l].)
//		}
//}
int maxIdx=0;
void lev(int  r) {
//	0 1 2  -- n-1
	queue<int>q;
//	queue<Node*>q;
	q.push(r);
	int lastIndex;
	while(!q.empty()) {
		int  fr=q.front();
		q.pop();
//		maxIdx=max(maxIdx,tr[fr].idx);
		int idx=tr[fr].idx;
		maxIdx=max(maxIdx,idx);
		if(idx==n-1) {
			lastIndex=fr;
		}
		if(tr[fr].l!=-1) {
			q.push(tr[fr].l);
			tr[tr[fr].l].idx=idx*2+1;
		}
		if(tr[fr].r!=-1) {
			q.push(tr[fr].r);
			tr[tr[fr].r].idx=idx*2+2;
		}
	}
	if(maxIdx==n-1) {
		printf("YES %d\n",lastIndex);
	} else {
		printf("NO %d\n",r);
	}
}

int main() {
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		string a,b;
		cin>>a>>b;
		if(a=="-") {
			tr[i].l=-1;
		} else {
			int ia=stoi(a);
			haveFa[ia]=1;
			tr[i].l=ia;
		}

		if(b=="-") {
			tr[i].r=-1;
		} else {
			int ib=stoi(b);
			haveFa[ib]=1;
			tr[i].r=ib;
		}
	}
	int r=0;
	for(int i=0; i<n; i++) {
		if(!haveFa[i]) {
			r=i;
			break;
		}
	}
	lev(r);
}

