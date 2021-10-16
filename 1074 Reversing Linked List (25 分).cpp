#include <bits/stdc++.h>
using namespace std;
int st, n, k;
class Node {
 public:
  int addr, val, ne;
  Node(int addr, int val, int ne) : addr(addr), val(val), ne(ne) {}
  Node() {}
};
// =stdc++11
// =std=c++11
// -std=c++11
vector<Node> v;
const int N = 1e5 + 8;
// int neIdx[N];
Node nodes[N];
void print(int j) {
    int i;
  for ( i = j + k - 1; i >= j+1; i--) {
    printf("%05d %d %05d\n", v[i].addr, v[i].val, v[i - 1].addr);
  }
   printf("%05d %d %05d\n", v[i].addr, v[i].val, v[j+k].addr);
}
int main() {
  scanf("%d%d%d", &st, &n, &k);
  for (int i = 0; i < n; i++) {
    int addr, val, ne;
    scanf("%d%d%d", &addr, &val, &ne);
    nodes[addr] = {addr, val, ne};
    //   v.push_back({addr,val,ne});
  }
  for (int i = st; i != -1; i = nodes[i].ne) {
    v.push_back(nodes[i]);
  }
  for (int i = 0; i < v.size();) {
    if (i + k < v.size()) {
      print(i);
      i += k;
    } else {
      int j;
      for (j = i; j < v.size() - 1; j++) {
        //   printf("%d ne\n",v[j + 1].addr);
        printf("%05d %d %05d\n", v[j].addr, v[j].val, v[j + 1].addr);
      }
      printf("%05d %d -1\n", v[j].addr, v[j].val);

      break;
    }
  }
}