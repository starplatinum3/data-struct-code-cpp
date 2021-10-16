

int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}

void uni(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  // fx  厉害
  if (per[fx] > per[fy]) {
    f[fy] = fx;
    per[fx] += per[fy];
    per[fy] = 0;
  }
}
