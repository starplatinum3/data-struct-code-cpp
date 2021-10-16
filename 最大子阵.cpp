#include <cstdio>
const int N = 500+5, INF = 0x3f3f3f3f;
int matrix[N][N];
// https://blog.csdn.net/qq_42835910/article/details/88638850
int main(int argc, char** argv) {
	int n, m, t;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d",&t);
			matrix[i][j] = matrix[i-1][j] + t;
		} 			
	int maxSum = -INF, sum;
	for(int k = 1; k <= n; k++){
        // k 从那一行开始加
		for(int i = k; i <= n; i++){
			sum = 0;
           
// -1 -4 3
// 3 4 -1
// -5 -2 8
// 假如 k 是2 ，那么
// 这两行相加
// 3 4 -1
// -5 -2 8

 // 所有列
			for(int j = 1; j <= m; j++){
				if(sum > 0) sum += matrix[i][j] - matrix[k-1][j];
                // k---i 这些行 的j 列， 和是多少 如果k==2，就是
 // -1 -4 3
 // (3) 4 -1
//  (-5)-2 8
// 然后j++ 继续下一列
// -1  -4   3
 // (3) (4) -1
//  (-5)(-2) 8
				else sum = matrix[i][j] - matrix[k-1][j];
				if(sum > maxSum) maxSum = sum;				
			}	
		}
	}
	printf("%d\n",maxSum);
	return 0;
}