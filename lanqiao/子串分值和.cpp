#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int maxn=1e6+5;
const int mod=1e9+7;
const int inf=1e18;
const int base=131;
const double pi=3.1415926;
#define ll long long
#define ull unsigned long long
#define maxx(a,b) (a>b?a:b)
#define minx(a,b) (a<b?a:b)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define debug(...) fprintf(stderr, __VA_ARGS__)
inline ll qpow(ll base, ll n) { assert(n >= 0); ll res = 1; while (n) { if (n & 1) res = res * base % mod; base = base * base % mod; n >>= 1; } return res; }
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) { return a*b/gcd(a,b); }
ll inv(ll a) {return a == 1 ? 1 : (ll)(mod - mod / a) * inv(mod % a) % mod;}
ll C(ll n,ll m){if (m>n) return 0;ll ans = 1;for (int i = 1; i <= m; ++i) ans=ans*inv(i)%mod*(n-i+1)%mod;return ans%mod;}
ll A(ll n,ll m){ll sum=1; for(int i=n;i>=n-m+1;i--) sum=(sum*i)%mod; return sum%mod;}
ll GetSum(ll L, ll R) {return (R - L + 1ll) * (L + R) / 2ll;} //等差数列求和 
 
/************/
char a[maxn];
int n,dp[maxn],pre[500],ans;
signed main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+i-pre[a[i]];
        // 上一个这个字符的位置
        // 中间那些都是有用的
        // ab useful 2
        // ababc
        // aba  之前的 a 是0 idx
        // 5-3 因为 a出现两次 所以是 ab 这两种可以的
        printf("dp[i] %d\n",dp[i]);
        int useful=i-pre[a[i]];
        printf("i %d ， 之前的字符是这个下标pre[a[i]] :%d\n",i,pre[a[i]] );
        printf("%d useful\n",useful);
        printf("%c\n",a[i]);
		pre[a[i]]=i;
		ans+=dp[i];
	}
	printf("%lld",ans);
	return 0;
}
