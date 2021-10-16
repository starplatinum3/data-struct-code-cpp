//1043 Is It a Binary Search Tree (25 ·Ö)
#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std;

//a 
class Node {
	public:
		int val;
		Node *l,*r;
		Node() {

		}
		Node(int val) :val (val) {
			this->l=nullptr;
			this->r=nullptr;
		}
};
int n;
Node * ins(int x, Node *t) {
	if(t==nullptr) {
		t=new Node(x);
	} else {
//		e right subtree of a node contains only nodes with keys greater than or equal to the node's key.
		if(x<t->val) {
			t->l=ins(x,t->l);
		} else if(x>=t->val) {
			t->r=ins(x,t->r);
		}
	}
	return t;
}

Node * insMi(int x, Node *t) {
	if(t==nullptr) {
		t=new Node(x);
	} else {
//		e right subtree of a node contains only nodes with keys greater than or equal to the node's key.
		if(x>=t->val) {
			t->l=insMi(x,t->l);
		} else if(x<t->val) {
			t->r=insMi(x,t->r);
		}
	}
	return t;
}


vector<int>read;
vector<int>preL;
vector<int>preLMi;
vector<int>postL;
vector<int>postLMi;
void pre(Node *t) {
	if(t==nullptr)
		return;
	preL.emplace_back(t->val);
	pre(t->l);
	pre(t->r);
}

void post(Node *t) {
	if(t==nullptr)
		return;


	post(t->l);
	post(t->r);
	postL.emplace_back(t->val);

}

void postMi(Node *t) {
	if(t==nullptr)
		return;

	postMi(t->r);
	postMi(t->l);
	postLMi.emplace_back(t->val);

}




void preMi(Node *t) {
	if(t==nullptr)
		return;
	preLMi.emplace_back(t->val);
	preMi(t->r);
	preMi(t->l);
}

void printV(vector<int>v) {
	for(int val:v) {
		cout<<val<<" ";
	}
	putchar('\n');
}
int main() {
	scanf("%d",&n);
	Node *t=nullptr;
	Node *tMi=nullptr;
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d",&x);
		read.emplace_back(x);
		t=ins(x,t);
		tMi=ins(x,tMi);
	}
	pre(t);
	preMi(t);

//	cout<<"pre\n";
//	printV(preL);
//		cout<<"preMi\n";
//	printV(preLMi);
	post(t);

//			cout<<"post\n";
//	printV(postL);

	postMi(t);
	if(read==preL) {
		printf("YES\n");


		int fir=1;

		for(int val:postL) {
			if(fir)fir=0;
			else printf(" ");
			printf("%d",val);
		}
		return 0;
	} else if(read==preLMi) {
		printf("YES\n");

		int fir=1;

		for(int val:postLMi) {
			if(fir)fir=0;
			else printf(" ");
			printf("%d",val);
		}
			return 0;
	} else {
//		NO Ð´´íÁË 
		printf("NO\n");
		return 0;
	}

}
