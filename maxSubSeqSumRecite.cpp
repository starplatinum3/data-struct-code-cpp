
int tmp, maxSum = -1;
int x, y;
int main() {
  int l = 0, r = n - 1;
  for (int i = 0; i < n; i++) {
    tmp += a[i];
    if (tmp < 0) {
      tmp = 0;
      x = i + 1;
    } else if (tmp>maxSum){
        maxSum=tmp;
        r=i;
        l=x;
    }
  }
  if(maxSum<0)maxSum=0;
  
}