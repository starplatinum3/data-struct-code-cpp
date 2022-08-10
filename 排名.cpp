#include <bits/stdc++.h>

// https://www.nowcoder.com/test/question/done?tid=59443170&qid=1288005#summary
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    std::vector<std::tuple<int, int, std::string>> arr;
    int cnt;
    std::cin >> cnt;
    for (int i = 0; i < cnt; i++) {
      std::string name;
      int bigScore, smallScore;
      std::cin >> name >> bigScore >> smallScore;
      arr.emplace_back(-bigScore, -smallScore, name);
    }
    // 根据tuple 排序 先是big 
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < cnt; i++) {
      std::cout << std::get<2>(arr[i]) << " \n"[i + 1 == cnt];
    }
  }
}