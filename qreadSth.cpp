//
// Created by Lenovo on 2020/12/4.
//

//作者：KellyFrog
//        链接：https://www.zhihu.com/question/426117879/answer/1567039719
//来源：知乎
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define rg register
#define mp make_pair
#define pb push_back
#define pf push_front

#define rep(i, s, t) for(rg int i = s; i <= t; i++)
#define per(i, s, t) for(rg int i = t; i >= s; i--)
#define debug(x) cerr << (#x) << " = " << (x) << "\n"

inline void qread() {}
template<typename T1, typename ...T2>
inline void qread(T1 &x, T2&... ls) {
    x = 0;
    rg char ch = ' '; rg int ps = 1;
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') ps = -1, ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= ps;
    qread(ls...);
}

template<typename T>
inline void qwrite(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) return putchar('0' + x), void();
    qwrite(x / 10), putchar('0' + (x % 10));
}

template<typename T>
inline void qwrite(T x, char ch) {
    qwrite(x), putchar(ch);
}

template<typename T>
inline void chkmax(T& x, T y) {
    if(x < y) x = y;
}

template<typename T>
inline void chkmin(T& x, T y) {
    if(x > y) x = y;
}

template<typename T>
inline void chkmod(T& x, ll mod) {
    x = x > mod ? x - mod : x;
}

template<typename T>
inline void chkadd(T& x, T y, ll mod) {
    x = x + y > mod ? x + y - mod : x + y;
}

template<typename T>
inline void chkmns(T& x, T y, ll mod) {
    x = x - y < 0 ? x - y + mod : x - y;
}

ll qpow(ll x, ll p, ll mod) {
    rg ll base = x, res = 1;
    while(p) {
        if(p & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        p >>= 1;
    }
    return res;
}

int main() {
    return 0;
}