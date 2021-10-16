// https://blog.csdn.net/u014117943/article/details/104597516

#include <bits/stdc++.h>

using namespace std;

map<string,int> vis;
string sc;

int game(string sc){
	if(vis.count(sc)){
		return vis[sc];
	}

	if(sc.find("LOL") != -1){
		//找到了
		return -1; 
        // 为什么是-1
	}
	// LLL  填都填完了，还是找不到空格，大家都用尽全力，都没找到LOL 所以是平局
	if(sc.find("*") == -1){
		// 没有空格 
		return 0;
	}
	bool ping = false;
	for(unsigned int i = 0 ; i < sc.size();i++){
		
		if(sc[i] == '*'){
			string tmp = sc;
			tmp[i] = 'L';
			int f = game(tmp);
//   L** LL LLL
// L***  L**L  L**L 
// 也就是说 填L 更容易输  猜的  
			if(f == -1){
                // 如果多加了个L 之后会变成-1 也就是会输。
                // 那么不加L的话 就会赢
                // 这是什么道理啊
                // 意思就是说另外一个人填了一个东西 他输了，咱就赢了
				return vis[sc] = 1;
			}else if(f == 0){
				ping = true;
			}
				
			tmp[i] = 'O';
			f = game(tmp);
// 填O 竟然也是一样的 我也不懂
			if(f == -1){
				return vis[sc] = 1;
			}else if(f == 0){
				ping = true;
			}
					
		}
		
	}

	if(ping){
		return vis[sc] = 0;
	}
	return vis[sc] = -1;
}

int main(){
	int n;
	scanf("%d",&n);
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		cout << game(str) << endl;
	}
	

	return 0;
}
