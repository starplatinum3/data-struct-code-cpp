
bool ok = true;
// https://blog.csdn.net/qq_38677814/article/details/82314153
void build(int prel, int inl, int postl, int n) {
  if (n == 2) ok = false;
  if (n == 0) return;
  if (n == 1) {
    in[inl] = pre[prel];
    return;
  }

  int nextRoot = postl + n - 2;
  int pos;
  for (int i = inl;; i++) {
    if (pre[i] == post[nextRoot]) {
      pos = i;
      break;
    }
  }
  int L = pos - prel - 1;
  int R = n - L - 1;
  build(prel + 1, inl, postl, L);
  build(prel + L + 1, inl + L + 1, postl + L, R);
}