#include<bits/stdc++.h>
int cntCity,cntWay,cntCheck;

// ������Ҫ�޵ĵ�·������ͨ���ĸ���-1

// ��ͨ�����
// ��������������������������������
// ��Ȩ����������ΪCSDN����������_yl����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
// ԭ�����ӣ�https://blog.csdn.net/qq_36589706/article/details/87916890


int main(){
    scanf("%d%d%d", &cntCity, &cntWay, &cntCheck);
    for(int i=0;i<cntWay;i++){
        
    }
}


#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1010;
const int INF=1000000000;
int N, M, K;
int d[maxn][maxn], visit[maxn];
vector<int>G[maxn];
int query;
void dfs(int index){
	if(index==query)return;
//     ����� ��Ҫȥ����
	visit[index]=1;
	for(int i=0; i<G[index].size(); i++){
		int v=G[index][i];
		if(visit[v]==0){
			dfs(v);
		}
	}
}
int main(){
	int a, b;
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<M; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0; i<K; i++){
		int cnt=0;
		scanf("%d",  &query);
		memset(visit, 0, sizeof(visit));
		for(int j=1; j<=N; j++){
//             query ���ų��� ÿ����һ��û��vis �� ��cnt++
//              ��Ϊ �����ͨ�Ļ� ��Щ��� vis ��
//             û��vis ����һ���µĲ���ͨ�Ŀ���
// 1 2 
// 1 3
// ���1 ������ 2 3 ����Ҫ������
			if(visit[j]==0&&j!=query){
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n", cnt-1);
	}
	return 0;
}
