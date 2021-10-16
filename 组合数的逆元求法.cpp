//组合数的逆元求法
//
//
// https://blog.csdn.net/qq_36979930/article/details/81698003

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 7;
//  组合数的逆元求法
ll fac[maxn];
ll inv[maxn];
ll C(int m, int n) {
  if (m > n) return -1;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

ll quick_mod(ll a, ll m) {
  ll tmp = a % mod;
  ll ans = 1;
  while (m) {
    if (m & 1) ans = ans * tmp % mod;
    tmp = tmp * tmp % mod;
    m >>= 1;
  }
  return ans;
}

void init() {
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = (fac[i - 1] * i) % mod;
  inv[maxn - 1] = quick_mod(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % mod;
}

int main() {
  init();
  ll n, m;
  //    cout<<"3*3/(C(6,3)): "<< 3*3*1.0/(C(3,6))<<"\n";
  // double nn=C(3,19)*1.0/C(4,20)*0.1+0.1/C(4,20)*(2*C(3,18)+C(2,18));
  //  double ann=pow(13,4)*1.0/C(4,52);

    cout<<C(2,96)*1.0*C(1,4)/C(3,100)<<"\n";
//   double ann = 1 - C(2, 7) * 1.0 / C(2, 10);
//   cout << C(2, 7) << "\n";
//   cout << C(2, 10) << "\n";
//   cout << ann << "\n";
  // cout<<1-nn<<"\n";
  //    cout<<0.8+
  //    C(3,19)*1.0/C(4,20)*0.1+0.1/C(4,20)*(2*C(3,18)+C(2,18))<<"\n";
  //   cout<< "sqrt(3)/2: " <<sqrt(3)/2<<"\n";
//   double res = 5 * 4 * 3 * 2 * 1.0 / (210);
//   double c10_4 = 10 * 9 * 8 * 7 * 1.0 / (4 * 3 * 2 * 1);
//   cout << "4*3*1.0/(C(3,10)) :" << 4 * 3 * 1.0 / (C(3, 10)) << "\n";
//   cout << "c10_4: " << c10_4 << "\n";
//   cout << "res: " << res << "\n";
//   cout << C(10, 4) << "\n";
//   cout << C(4, 10) << "\n";
  //    while(cin>>n>>m)
  //        cout << C(m,n) << endl;  //n 是下面的， m 是上面的 , n大

  return 0;
}
