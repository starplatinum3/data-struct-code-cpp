
#include <bits/stdc++.h>
using namespace std;
int m, n, p;
const int N = 1e4;
string nas[N];
map<string, int> mp;
// 这个还不对
// https://www.baidu.com/link?url=7bdVOYJ0ye1FZUXGZKdeLvyr-ZB0FUWcNpGFdgTiuTMzz7RIWayDiBqIbcnMvhyNOjcd4mBynYNocmjyW3LN8soee9-iXeb6ho7antze2Xm&wd=&eqid=a6489549000d576600000005604b5cc9
int main() {
  scanf("%d%d%d", &m, &n, &p);
  for (int i = 0; i < m; i++) {
    //  string str;
    cin >> nas[i];
  }
  for (int i = p; i < m;) {
    if (mp[nas[i]] == 0) {
      mp[nas[i]] = 1;
      cout << nas[i] << "\n";
      i += n;
    } else {
      i++;
    }
  }
}