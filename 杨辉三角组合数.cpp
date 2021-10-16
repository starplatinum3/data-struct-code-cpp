// 这个杨辉三角 可以直接弄出组合数
#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 10007;
const int maxn = 1000 + 5;
int C[maxn][maxn];
int pow(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  int k = b % 2;
  int ans = (pow(a, b / 2) * pow(a, b / 2)) % mod;
  if (k) ans *= a;
  ans %= mod;
  return ans;
}
int main() {
  // freopen("in.txt","r",stdin);
  for (int i = 1; i <= 1000; ++i) C[i][i] = C[i][0] = 1;
  for (int i = 2; i <= 1000; ++i)
    for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//   printf("%d\n", C[4][2]);
  // 4*3
  // 2
  // for(int i=1;i<=5;i++)
  // {
  // 	for(int j=1;j<=5;j++)
  // 	{
  // 		printf("i==%d,j==%d ",i,j);
  // 		printf("%d\n",C[i][j]);
  // 	}

  // }
// cout<<3*1.0/8<<"\n";
cout<<C[96][2]*1.0*C[4][1]/C[100][3]<<"\n";
//   cout<<1-0.68-0.85*(1-0.8) -0.8*(1-0.85);
// cout<<C[4][3]*C[96][1]*1.0/C[100][4];
//   printf("%.f\n",C[4][3]*C[96][1]*1.0/C[100][4]);
//   int a, b, k, n, m;
//   cin >> a >> b >> k >> n >> m;

//   a %= mod, b %= mod;
//   int ans = (pow(a, n) * pow(b, m)) % mod;
//   ans = (ans * C[k][n]) % mod;
//   printf("%d", ans);
  return 0;
}
