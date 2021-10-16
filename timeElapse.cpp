#include <bits/stdc++.h>
using namespace std;
int mo[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//class MyDate {
// public:
//  int y, m, d;
//  MyDate(int y, int m, int d) : y(y), m(m), d(d) {}
//  int timeElapse(MyDate date1, MyDate date2) {
//    return timeElapse(date1.y, date1.m, date1.d, date2.y, date2.m, date2.d);
//  }
//  int timeElapse(int y1, int mon1, int d1, int y2, int mon2, int d2) {
//    return timeElapse(y2, mon2, d2) - timeElapse(y1, mon1, d1);
//  }
//};
// 错的
 int isLeap(int y) {
  return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}
int timeElapse(int y, int m, int d) {
  int res = d;
   if (m > 2 && isLeap(y)) res++;
  y--;
  res += y / 4 + y / 400 - y / 100 + y * 365;
  //        每4年有个闰年，每400年有个闰年，但是每400年，也就是有个100，所以把他去掉
  for (int i = 1; i <= 12 && i <= m; i++) {
    res += mo[i];
  }
 
  return res;
}

int timeElapse(int y1, int mon1, int d1, int y2, int mon2, int d2) {
  return timeElapse(y2, mon2, d2) - timeElapse(y1, mon1, d1);
}

int main() {
   int y1,  mon1,  d1,  y2,  mon2,  d2;
   y1=2019;
   mon1=9;
   d1=7;
   y2=2019;
   mon2=9;
   d2=10;
   scanf("%d%d%d%d%d%d",&y1,  &mon1,  &d1,  &y2,  &mon2,  &d2);
//   scanf("%d%d%d",&y1,&mon1,&d1);
//   printf("%d\n",timeElapse(y1,mon1,d1));
    printf("You have lived %d days.\n",timeElapse(y1,mon1,d1,y2,mon2,d2));
}
