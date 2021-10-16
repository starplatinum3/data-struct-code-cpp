//1032 Sharing (25 ·Ö)
#include<bits/stdc++.h>
using namespace std;
int addr1,addr2;
int cntNode;
class Node{
	public:
	int addr;
	char data;
	int ne;
	Node(){
	}
	Node(int addr,char data,int ne){
		this->addr=addr;
		this->data=data;
		this->ne=ne;
	}
};
vector<Node>lst1;
vector<Node>lst2;
vector<Node>addrJump;
int  findSameAddr(int addr){
	for(int ad=addr2;ad!=-1;ad=addrJump[ad].ne){
		if(ad==addr){
			return ad;
		}
	}
	return -1;
}
//https://blog.csdn.net/minose/article/details/81662828
const int MAX_NODE_CNT=100008;
bool vis[MAX_NODE_CNT];
int main(){
	scanf("%d%d%d",&addr1,&addr2,&cntNode);
//	positive N (¡Ü10 ^5 
 addrJump.resize(100008); 
	for(int i=0;i<cntNode;i++){
		int addr,ne;
		char data;
		scanf("%d %c %d",&addr,&data,&ne);
		addrJump[addr]=Node(addr,data,ne);
//		lst.emplace_back(addr,data,ne);
	}
	int ans=-1;
	for(int addr=addr1;addr!=-1;addr=addrJump[addr].ne){
		vis[addr]=true;
//		int res=findSameAddr(addr);
//		if(res!=-1){
//			ans=res;
//			break;
//		}
	}
	int have=0;
	for(int addr=addr2;addr!=-1;addr=addrJump[addr].ne){
		if(vis[addr]){
				printf("%05d\n",addr);
				have=1;
				break;
		}
	}
	if(have==0){
			printf("-1\n");
	}
//	if(ans==-1){
//		printf("-1\n");
//	}else 
//	printf("%05d\n",ans);
} 
