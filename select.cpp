#include <iostream>
using namespace std;
int n, k, sum, ans;
int a[40];
bool xuan[40];

void printXuan(){
	printf("xuan \n");
	for(int i=0;i<333;i++){
		if(xuan[i]){
			
			printf("[%d]%d, ",i,a[i]);
		}
	}
	putchar('\n');
}


void dfs(int s, int cnt,int pos) {
    if(s>sum||cnt>k){
		return ;
    }
    if (s == sum && cnt == k) {
        ans++;
        printXuan();
    }
    for (int i = pos; i < n; i++) {
        if (!xuan[i]) {
            xuan[i] = 1;
            dfs(s + a[i], cnt + 1,i+1);
            xuan[i] = 0;
        }
    }
}
int main() {
    n = 30;
    k = 8;
    sum = 200;
    for (int i = 0; i < 30; i++) {
        a[i] = i + 1;
    }
    ans = 0;
    dfs(0, 0,0);
    cout << ans << endl;
    return 0;
}

