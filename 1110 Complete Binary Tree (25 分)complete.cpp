
//1110 Complete Binary Tree (25 ·Ö)
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int n;
const int N=22;
vector<int>g[N];
int root;
int fa[N];
int maxIdx=0;
int lastNode;
class Node{
	public:
		int id,dep;
		int idx;
		Node(int id,int dep,int idx):
			id(id),dep(dep),idx(idx){
			}
			
				Node(int id,int idx):
			id(id),idx(idx){
			}
};
void bfs(){
	queue<Node>q;
	q.push({root,0});
	while(!q.empty()){
    	Node fr=	q.front();
    	q.pop();
    	int id=fr.id;
    	int idx=fr.idx;
//    	printf(" id %d idx %d\n",id,idx);
    	if(g[id][0]!=-1){
    			q.push({g[id][0],idx*2+1});
		}
		if(g[id][1]!=-1){
    			q.push({g[id][1],idx*2+2});
		}
		if(maxIdx<idx){
			maxIdx=idx;
			lastNode=id; 
		}
//		maxIdx=max(maxIdx,idx);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
//		char a,b;
//		scanf(" %c %c ",&a,&b);
		string a,b;
		cin>>a>>b;
	
		int ia,ib;
		if(a=="-"){
			ia=-1;
		}else{
				 ia=stoi(a);
		}
		
		if(b=="-"){
			ib=-1;
		}else{
			ib=stoi(b);
		}
		fa[ia]=fa[ib]=1;
	 g[i].push_back(ia);
	  g[i].push_back(ib);
//		int ib=stoi(b);
		
	}
	
	for(int i=0;i<n;i++){
		if(fa[i]==0){
			root=i;
		}
	}
	bfs();
	if(maxIdx==n-1){
		printf("YES %d\n",lastNode);
	}else{
		printf("NO %d\n",root);
	}
}
