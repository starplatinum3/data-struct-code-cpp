
int bit[N];
int lowbit(int x) { return x & (-x); }
int add(int x, int idx) {
  for (int i = idx; i <= n; i += lowbit(i)) {
    bit[i] += x;
  }
}

int sum(int idx) {
  int res = 0;
  for (int i = idx; i > 0; i-=lowbit(i)) {
    res += bit[i];
  }
  return res;
}