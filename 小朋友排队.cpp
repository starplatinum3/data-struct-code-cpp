#include <stdio.h>
#include <string.h>
const int M = 1e6 + 10;  //注意这种定义方法代表10的6次方

const int N = 1e5 + 10;
int H[N], b[N],
    c[M];  // H数组对应树状数组中的a数组，b记录了每个小朋友交换的次数，
    // c对应了树状数组的c数组，以备求和
int lowbit(
    int x)  // lowbit函数求的是2^k,k是层数，从第0层开始向上，k的值是x（二进制表示）从右往左第一个1的位置。

{  //第x项的项数就是2^k项
  return x & -x;
}
int sum(int i)  //求和1~x的和
{
  int ans = 0;
  while (i > 0) {
    ans += c[i];
    i -= lowbit(i);
  }
  return ans;
}
void add(
    int d,
    int x)  //原意为修改c[x]的值，这里指的是一个个将输入的身高插入到数组c中，

//以便计算第x个小朋友之前的比他矮的人数
{
  while (x <= M) {
    c[x] += d;  //该题中d的值始终为1
    x += lowbit(x);  //树状数组中数组a一个值改变，会引起c的多个值改变
  }
  return;
}
// https://blog.csdn.net/emilyhoward/article/details/60467755
int main() {
  int n, i;
  scanf("%d", &n);
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  for (i = 1; i <= n; i++) {
    scanf("%d", &H[i]);
    add(1, H[i] + 1);  //注意身高+1来对应下标
    b[i] = i - sum(H[i]) -1;  
    // ，b记录了每个小朋友交换的次数，
    // 1--H[i] 的和
    //减去比H[i]（+1）矮的人数 ，及他自己，i为当前插入的人数
    // sum 比H[i]小于等于的人数 
    b[i] -= sum(H[i] + 1) - sum(H[i]) -1;  
    // 小于等于(H[i] + 1的人数 - 小于等于(H[i] 的人数 得到的是H[i] + 1高度的人数
    //再减去和H[i]一样高的人数
                //，因为只能求出前i项和，所以求单独一项i的值，需要
  }  //前i项的和减去前i-1项的和，此题还需要减去自己（-1），剩下比他高的人
//   现在剩下的是比他高的人数吗
  memset(c, 0, sizeof(c));  // c数组清零，倒着插入，求其后比其矮的人
  for (i = n; i >= 1; i--) {
    add(1, H[i] + 1);
    b[i] += sum(H[i]);  //比H[i]+1矮的人数，（H[i]+1是高度+1 ，之前有说明
  }
  long long r = 0;  //数比较大，用long long
  for (i = 1; i <= n; i++) {
    r += (long long)b[i] * (b[i] + 1) /2; 
    // 1 2 3 4 5   6  交换次数
    // 1 3 6 10 15 21（1+2+~6==（1+6）*6/2==3*7=21）
     //等差数列求和，需要类型强制转换，要不然存不下
  }  //每个小朋友i的交换次数为b[i],1~b[i]等差数列求和，再求n个小朋友的总和
  printf("%lld\n", r);
  return 0;
}