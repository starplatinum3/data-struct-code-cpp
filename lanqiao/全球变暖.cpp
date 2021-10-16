#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a[1001][1001];
int b[1001][1001];
long long int s = 0;
int n;
int v[10001];
void fun(int x,int y)
{
	int flag = 0;
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			if(i==j||(i+j)==0)
				continue;
			int nx = x + i;
			int ny = y + j;
			if(nx>=0&&ny>=0&&nx<n&&ny<n){
				if(a[nx][ny]==0){
                    // 如果 下一个 是水
					flag = 1;
				} 
			}
		}
	}
    // 没有被水淹没  那么他还是保留的
	if(!flag){
		b[x][y] = a[x][y];
	}
}
 
void dfs(int x,int y,int value)
{
	
	if(a[x][y]!=1){
		return ;
	}
	
	a[x][y] = value;
	
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			if(i==j||(i+j)==0)
				continue;
			int nx = x + i;
			int ny = y + j;
			if(nx>=0&&ny>=0&&nx<n&&ny<n){
				dfs(nx,ny,value);
			}
		}
	}
	
}
 
int main()
{
	
	char ch;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>ch;
			if(ch=='.'){
				a[i][j] = 0;       //0代表陆地 
			}
			else if(ch=='#'){
				a[i][j] = 1;       //1代表岛屿 
			}
		}
		getchar();
	}
	
	int value = 10;                //为刚开始的时候岛屿分配一个号码 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				dfs(i,j,value++);
			}
		}
	}
	
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=0){
				fun(i,j);       //判断是否沉没 
			}
		}
	}
	
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<b[i][j];
		}
		cout<<endl;
	}*/
	
	int a = value - 10;
    // 从10 开始，所以一共有多少个岛屿
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]!=0){
				v[b[i][j]]++; //判断淹没后多出来的岛屿数 
                // 这里直接 res++ 好不好
			}
		}
	}
	
	for(int i=0;i<10001;i++){
		if(v[i]){
			res++;
		}
	}
	
	cout<<a-res;
    // 总共的- 剩下的岛屿
	
	return 0;
}