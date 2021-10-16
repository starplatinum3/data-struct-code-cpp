#define LOCAL
#include <stdio.h>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1000 + 5;
int n;
int rate[24];

struct Record{
  string name;
  int month;
  int dd, hh, mm;
  int state;

  bool operator < (const Record &r) const {
    if(name < r.name) return true;
    if(name == r.name) {
      if(dd < r.dd) return true;
      if(dd == r.dd && hh < r.hh) return true;
      if(dd == r.dd && hh == r.hh && mm < r.mm) return true;
    }
    return false;
  }
}rec[maxn];
map<string, vector<Record> > mp;

pii cal(int dd, int hh, int mm) {
  int tol_min = 0, tol_cost = 0;
  int day_rate = 0;
  for(int i = 0; i < 24; i++) day_rate += rate[i] * 60;
  tol_min += dd * 24 * 60 + hh * 60 + mm;
  tol_cost += dd * day_rate + mm * rate[hh];
  for(int i = 0; i < hh; i++) {
    tol_cost += rate[i] * 60;
  }
  return make_pair(tol_min, tol_cost);
}

void solve() {
  sort(rec, rec + n);
  for(int i = 0; i < n-1; i++) {
    if(rec[i].name == rec[i+1].name && rec[i].state == 1 && rec[i+1].state == 0) {
      mp[rec[i].name].push_back(rec[i]);
      mp[rec[i+1].name].push_back(rec[i+1]);
    }
  }
  for(map<string, vector<Record> >::iterator it = mp.begin(); it != mp.end(); ++it) {
    cout << it->first << " ";
    vector<Record> records = it->second;;
    printf("%02d\n", records[0].month);

    int tol_cost = 0;
    for(int i = 0; i < records.size(); i += 2) {
      pii a = cal(records[i].dd, records[i].hh, records[i].mm);
      pii b = cal(records[i+1].dd, records[i+1].hh, records[i+1].mm);
      printf("%02d:%02d:%02d %02d:%02d:%02d", records[i].dd, records[i].hh, records[i].mm, records[i+1].dd, records[i+1].hh, records[i+1].mm);
      printf(" %d $%.2f\n", b.first - a.first, (b.second - a.second) * 1.0 / 100);
      tol_cost += b.second - a.second;
    }
    printf("Total amount: $%.2f\n", tol_cost * 1.0 / 100);
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
#endif
  for(int i = 0; i < 24; i++) {
    scanf("%d", &rate[i]);
  }
  scanf("%d", &n);
  char sta[25];
  for(int i = 0; i < n; i++) {
    cin >> rec[i].name;
    scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
    scanf("%s", sta);
    if(sta[1] == 'n') rec[i].state = 1;
    else rec[i].state = 0;
  }
  solve();
  return 0;
}


