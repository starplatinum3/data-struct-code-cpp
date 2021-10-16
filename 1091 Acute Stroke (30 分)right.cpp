#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;

const int N = 129;
int map[1300][130][80];
bool vst[1300][130][80];
int m,n,l,t;

int dirX[6] = {1,0,-1,0,0,0};
int dirY[6] = {0,1,0,-1,0,0};
int dirZ[6] = {0,0,0,0,1,-1};

struct state {
	int x,y,z;
	state(int a,int b,int c) {
		x = a;
		y = b;
		z = c;
	}
};

bool check(state s) {
	if(s.x < 0 || s.x >= m || s.y < 0 || s.y >= n || s.z < 0 || s.z >= l)
		return false;
	if(vst[s.x][s.y][s.z] == true ||  map[s.x][s.y][s.z] == 0) return false;
	else
		return true;
}

int bfs(int a,int b,int c) {
	int cnt = 0;
	state s(a,b,c);
	queue<state> que;
	que.push(s);
	vst[a][b][c] = true;
	while(!que.empty()) {
		cnt++;
//		ÿ����
		state now = que.front();
		que.pop();
		for(int i=0; i<6; i++) {
			state next = now;
//			ֻ���� x yz  һ��������
//ͼƬ Ϊʲô��4����ĺ���������һ�� ����z�ܶ���һ������
			next.x = now.x + dirX[i];
			next.y = now.y + dirY[i];
			next.z = now.z + dirZ[i];
			if(check(next)) {
				vst[next.x][next.y][next.z]	 = true;
				que.push(next);
			}
		}
	}
	if(cnt >= t)
		return cnt;
	else
		return 0;
}

void printG() {
	printf("======Graph=====\n");
	for(int i=0; i<l; i++) { //Z��
	printf("Z�� %d\n",i);
		for(int j=0; j<m; j++) { //X����
			for(int k=0; k<n; k++) { //Y��
				printf("%d ",map[j][k][i]);
			}
			printf("\n");
		}
		printf("\n");
	}



//				scanf("%d",&map[j][k][i]);//ע���±��ӦΪ(x,y,z)
}
int main() {
	cin>>m>>n>>l>>t;

	for(int i=0; i<l; i++) //Z��
		for(int j=0; j<m; j++) //X����
			for(int k=0; k<n; k++) //Y��
				scanf("%d",&map[j][k][i]);//ע���±��ӦΪ(x,y,z)


printG();
	int sum = 0;
	for(int i=0; i<l; i++)
		for(int j=0; j<m; j++)
			for(int k=0; k<n; k++) {
				state s(j,k,i);
				if(check(s)) {
					sum += bfs(j,k,i);
				}
			}
	printf("%d",sum);

	return 0;
}
