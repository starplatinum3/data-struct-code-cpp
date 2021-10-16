//1102 Invert a Binary Tree (25 ·Ö)

#include<bits/stdc++.h>
using namespace std;
int n;
const int    MAX_N=22;
vector<int>tree[MAX_N];
bool havaFa[MAX_N];
void level(int root) {
	vector<int>levelArr;
	queue<int>q;
	q.push(root);
	while(!q.empty()) {
		int fr= q.front();
		q.pop();
		levelArr.emplace_back(fr);

		if(tree[fr].size()) {
			for(int i=tree[fr].size()-1; i>=0; i--) {
				int val=tree[fr][i];
				if(val!=-1) {
					q.push(val);
				}

			}
//            for(auto val: tree[fr]){
//                q.push(val);
//            }
		}
	}
	int fir=1;
	for(auto val:levelArr) {
		if(fir)fir=0;
		else printf(" ");
		printf("%d",val);
	}
	putchar('\n');
}
int inFir=1;
void in(int node) {
	if(node==-1)return;
//     if(tree[node].size()>=2)
	in(tree[node][1]);
	if(inFir)inFir=0;
	else printf(" ");
	printf("%d",node);

//      if(tree[node].size()>=1)
	in(tree[node][0]);
}
int main() {
	scanf("%d", &n);
	getchar();
//    printf("n: %d\n",n);
	for(int i=0; i<n; i++) {
		char u,v;
		scanf("%c %c",&u,&v);
		getchar();
		if(u!='-') {
			tree[i].emplace_back(u-'0');
			havaFa[u-'0']=1;
		} else {
			tree[i].emplace_back(-1);
		}
		if(v!='-') {
			tree[i].emplace_back(v-'0');
			havaFa[v-'0']=1;
		} else {
			tree[i].emplace_back(-1);
		}

	}
	int root=0;
	for(int nodeNum=0; nodeNum<n; nodeNum++) {
		if(!havaFa[nodeNum]) {
			root=nodeNum;
			break;
		}
	}

	level(root);
	in(root);



}
