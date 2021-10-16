//1111 Online Map (30 ��)
#include<bits/stdc++.h>
using namespace std;
class Edge {
	public:
		int u,v;
		int len,ti;
		Edge(int u,int v,int len,int ti):
			u(u),v(v),len(len),ti(ti) {
		}
		Edge() {
		}
};

class Node1 {
	public:
		int u,len;
		Node1(int u,int len):
			u(u),len(len) {

		}
		Node1() {
		}
		bool operator<(const Node1& rhs)const {
			return len<rhs.len;
		}
};


class Node2 {
	public:
		int u,ti;
		Node2(int u,int ti):
			u(u),ti(ti) {

		}
		Node2() {
		}

		bool operator<(const Node2& rhs)const {
			return ti<rhs.ti;
		}

};
const int N=555;
vector<int>g[N];
int n,m;
vector<Edge>eds;
int leng[N][N];
int tim[N][N];
const int INF=0x3f3f3f3f;
int toti[N],tolen[N];
int tmpToT[N],tmpToL[N];
int st,en;
bool visLen[N],visTi[N];
//vector<int>paLen[N];
int paLen[N],paT[N];
//vector<int>paLen[N];
int num[N];
void initDij() {
	for(int i=0; i<=n; i++) {
		tolen[i]=INF;
		toti[i]=INF;
		paLen[i]=-1;
		paT[i]=-1;
//		tmpToT[i]=INF;
//		num[i]=INF;
//num ���ø�ֵ inf ��Ϊÿ����һ��ʼ����0
	}
	tolen[st]=tmpToT[st]=tmpToL[st]=0;
	toti[st]=0;
//	num[st]=0;
}
void dij() {
	for(int i=0; i<=n; i++) {
		tolen[i]=INF;
		toti[i]=INF;
		paLen[i]=-1;
		paT[i]=-1;
		tmpToT[i]=INF;
		num[i]=INF;
	}
	tolen[st]=tmpToT[st]=tmpToL[st]=0;
	toti[st]=0;
	num[st]=0;
	priority_queue<Node1>q1;
	priority_queue<Node2>q2;
	q1.push(Node1(st,0));
	q2.push(Node2(st,0));
	while(!q1.empty()) {
		auto nod=q1.top();
		int u=nod.u;
//		int le=nod.len;
		q1.pop();
		visLen[u]=true;
		for(int v:g[u]) {
			if(visLen[v]||leng[u][v]==INF)continue;
			if(tolen[v]>tolen[u]+leng[u][v]) {
				tolen[v]=tolen[u]+leng[u][v];
				paLen[v]=u;
//paLen[v].clear();
//					paLen[v].push_back(u);
				tmpToT[v]=tmpToT[u]+tim[u][v];
			} else if(tolen[v]==tolen[u]+leng[u][v]
			          &&tmpToT[v]>tmpToT[u]+tim[u][v]) {
//				tolen[v]=tolen[u]+leng[u][v];
				paLen[v]=u;
				tmpToT[v]=tmpToT[u]+tim[u][v];
			}
			q1.push(Node1(v,tolen[v]));
		}
	}

	while(!q2.empty()) {
		auto nod=q2.top();
		int u=nod.u;
//		int le=nod.len;
		q2.pop();
		visTi[u]=true;
		for(int v:g[u]) {
			if(visTi[v]||tim[u][v]==INF)continue;
			if(toti[v]>toti[u]+tim[u][v]) {
				toti[v]=toti[u]+tim[u][v];
				paT[v]=u;
//paT[v].clear();
//					paT[v].push_back(u);
				num[v]=num[u]+1;
			} else if(toti[v]==toti[u]+tim[u][v]
			          &&num[v]>num[u]+1) {
//				toti[v]=toti[u]+tim[u][v];
				paT[v]=u;
				num[v]=num[u]+1;
			}
			q2.push(Node2(v,toti[v]));
		}
	}




}

void dijNor() {
	initDij();
//	��queue �Ͳ���ȷ��  ��֪����ô�㰡
	for(int i=0; i<n; i++) {
		int u=-1;
		int mi=INF;
		for(int j=0; j<n; j++) {
			if(visLen[j])continue;
			if(tolen[j]<mi) {
				mi=	tolen[j];
				u=j;
			}
		}
//		printf("u %d\n",u);
		if(u==-1)break;
		visLen[u]=true;
//		for(int v:g[u]) {
		for(int v=0; v<n; v++) {
			if(visLen[v]||leng[u][v]==INF)continue;
			if(tolen[v]>tolen[u]+leng[u][v]) {
//				printf("len v %d\n",v);
				tolen[v]=tolen[u]+leng[u][v];
				paLen[v]=u;
//paLen[v].clear();
//					paLen[v].push_back(u);
				tmpToT[v]=tmpToT[u]+tim[u][v];
			} else if(tolen[v]==tolen[u]+leng[u][v]
			          &&tmpToT[v]>tmpToT[u]+tim[u][v]) {
//				tolen[v]=tolen[u]+leng[u][v];
				paLen[v]=u;
				tmpToT[v]=tmpToT[u]+tim[u][v];
			}

		}
	}


//	for(int i=0; i<n; i++) {
//		int u=-1;
//		int mi=INF;
//		for(int j=0; j<n; j++) {
//			if(visTi[j])continue;
//			if(toti[j]<mi) {
//				mi=toti[j];
//				u=j;
//			}
//		}
//		if(u==-1)break;
//		visTi[u]=true;
//		for(int v=0;v<n;v++){
//
////		for(int v:g[u]) {
//			if(visTi[v]||toti[v]==INF)continue;
//			if(toti[v]>toti[u]+tim[u][v]) {
//				toti[v]=toti[u]+tim[u][v];
//				paT[v]=u;
//				num[v]=num[u]+1;
//			} else if(toti[v]==toti[u]+tim[u][v]&&
//			          num[v]>num[u]+1) {
//				num[v]=num[u]+1;
//				paT[v]=u;
//			}
//		}
//	}

//wrong

//	while(1) {
//		int u=-1;
//		int mi=INF;
//		for(int j=0; j<n; j++) {
//			if(visTi[j])continue;
//			if(toti[j]<mi) {
//				mi=toti[j];
//				u=j;
//			}
//		}
//		if(u==-1)break;
//		visTi[u]=true;
//		for(int v=0; v<n; v++) {
//			if(visTi[v]||tim[u][v]==INF)continue;
//			if(toti[v]>toti[u]+tim[u][v]) {
//				toti[v]=toti[u]+tim[u][v];
//				paT[v]=u;
//				num[v]=num[u]+1;
//			} else if(toti[v]==toti[u]+tim[u][v]&&
//			          num[v]>num[u]+1) {
//				num[v]=num[u]+1;
//				paT[v]=u;;
//			}
//		}
//	}
//
	while(1) {
		int u=-1;
		int mi=INF;
		for(int i=0; i<n; i++) {
			if(!visTi[i]&&toti[i]<mi) {
				mi=toti[i];
				u=i;
			}
		}
		if(u==-1)break;
		visTi[u]=true;
//		for(int v:g[u]){

//		����ֱ��ѭ��
		for(int v=0; v<n; v++) {
//			���Ҫֱ��ѭ���Ļ� Ҫ��ȫ��inf
			if(visTi[v]||tim[u][v]==INF) {
//				printf("visTi[v] v  %d %d\n",visTi[v],v);
//				printf("tim[u][v] %d \n",tim[u][v]);
				continue;
			}

			if(toti[v]>toti[u]+tim[u][v]) {
				toti[v]=toti[u]+tim[u][v];
				num[v]=num[u]+1;
				paT[v]=u;
//				printf(" num[v] v %d %d\n",num[v],v);
			} else if(	toti[v]==toti[u]+tim[u][v]&&
			            num[v]>num[u]+1) {
//			            	printf("from ");
//			            	printf("paT[v] %d to ",paT[v]);
				num[v]=num[u]+1;
				paT[v]=u;
//					printf("paT[v] %d\n",paT[v]);
//					printf("num[v] %d\n",num[v]);
			}
		}
	}

//	cuode
//	for(int i=0; i<n; i++) {
//		int u=-1;
//		int mi=INF;
//		for(int j=0; j<n; j++) {
//			if(visTi[j])continue;
//			if(toti[j]<mi) {
//				mi=	toti[j];
//				u=j;
//			}
//		}
//		if(u==-1)break;
//		visTi[u]=true;
//		for(int v:g[u]) {
//			if(visTi[v]||tim[u][v]==INF)continue;
//			if(toti[v]>toti[u]+tim[u][v]) {
//				toti[v]=toti[u]+tim[u][v];
//				paT[v]=u;
////paT[v].clear();
////					paT[v].push_back(u);
//				num[v]=num[u]+1;
//
//			} else if(toti[v]==toti[u]+tim[u][v]
//			          &&num[v]>num[u]+1) {
////				toti[v]=toti[u]+tim[u][v];
//				paT[v]=u;
//				num[v]=num[u]+1;
//			}
//
//		}
//	}
}
bool equal() {
	for(int i=en,j=en; i!=-1&&j!=-1; i=paLen[i],j=paT[j]) {
		if(i!=j) {
			return false;
		}
	}
	return true;
}

void printPL() {
	vector<int>pa;
	for(int i=en; i!=-1; i=paLen[i]) {
		pa.push_back(i);
	}
	for(int i=pa.size()-1; i>=1; i--) {
		printf(" %d ->",pa[i]);
	}
	printf(" %d\n",pa[0]);
}

void printPT() {
	vector<int>pa;
	for(int i=en; i!=-1; i=paT[i]) {
		pa.push_back(i);
	}
	for(int i=pa.size()-1; i>=1; i--) {
		printf(" %d ->",pa[i]);
	}
	printf(" %d\n",pa[0]);
}
//a 

int main() {
	scanf("%d%d",&n,&m);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			leng[i][j]=INF;
			tim[i][j]=INF;
		}
	}
	for(int i=0; i<m; i++) {
		int v1,v2,onw,len,ti;
		scanf("%d%d%d%d%d", &v1,&v2,&onw,&len,&ti);
//		��������ط�
//  �����о���������дһ��Ĵ�ȽϿ�
//��Ȼ������ʱ���õ�ͦ��� ����������дһ���ʱ�� ��������
//�������õ��� onw ������ 
//��дҲ���������߼� 
//��Ȼ������ô�� ʱ�䶼û�˰� 
//Ҫ�ǿ��Ե�ʱ�������ֵط� ������ 
		if(!onw) {
			g[v2].push_back(v1);
			leng[v2][v1]=len;
			tim[v2][v1]=ti;
		}
		g[v1].push_back(v2);
		leng[v1][v2]=len;
		tim[v1][v2]=ti;
//			eds.emplace_back(v1,v2,len,ti);
	}
	scanf("%d%d",&st,&en);
//	dij();
	dijNor();
	if(equal()) {
		printf("Distance = %d; Time = %d:",
		       tolen[en],toti[en]);
		printPL();
	} else {
		printf("Distance = %d:",
		       tolen[en]);
		printPL();
		printf("Time = %d:",
		       toti[en]);
		printPT();
	}
}
