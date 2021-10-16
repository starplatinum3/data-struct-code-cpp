#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int maxn = 2005;
int a[maxn], n, t, cnt;

// https://blog.csdn.net/sugarbliss/article/details/81101493
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> t;
	for(int i = 1; i < (1 << n); i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
                sum += a[j];
        }
        if(sum == t)
        {
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                    cout << a[j] << " ";
            }
            cout << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
}