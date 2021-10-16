#include <iostream>
#include <string>
#include <queue>

using namespace std;

int maze[35][55];
int dir[][2] = { { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } };
char d[4] = { 'D', 'L', 'R', 'U' };
int cnt = 0x3f3f3f3f;
bool vis[35][55];

struct node{
	int x;
	int y;
	string rode;
	int step;
	node(int xx, int yy, string ss, int tt)
	{
		x = xx;
		y = yy;
		rode = ss;
		step = tt;
	}
};

bool check(int x, int y){
	if (x <= 30 && x >= 1 && y <= 50 && y >= 1){
		return true;
	}
	return false;
}

void bfs(int x, int y, string s, int num){
	queue<node> q;
	q.push(node(x, y, s, num));
	while (!q.empty()){
		node now = q.front();
		q.pop();

		vis[now.x][now.y] = true;

		if (now.x == 30 && now.y == 50){
			if (now.step < cnt){
				cnt = now.step;
				// cout << now.step << endl;
				cout<< now.rode << endl;
				vis[now.x][now.y] = false;
			}
			continue;
		}

		for (int i = 0; i < 4; i++){
			int tx = now.x + dir[i][0];
			int ty = now.y + dir[i][1];

			if (maze[tx][ty] == 0 && !vis[tx][ty] && check(tx, ty)){
				q.push(node(tx, ty, now.rode + d[i], now.step + 1));
			}
		}
	}
}

int main(){

	for (int i = 1; i <= 30; i++){
		for (int j = 1; j <= 50; j++){
			maze[i][j] = getchar()-'0';
		}
		getchar();
	}

	bfs(1, 1, "", 0);

	return 0;
}