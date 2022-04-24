#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>

using namespace std;

int main() {
    string str;
    cin >> str;
    map<char, int> mp;
    for (int i = 0; i < str.length(); ++i) {
        mp[str[i]]++;
    }
    int start = 0, cur = 0, end;
    vector<int> ans;
    for (int i = 0; i < str.length(); ++i) {
        if (mp[str[cur]] == 0) {
            bool flag = false;
            for (int j = 1; j < i; ++j) {
                if (mp[str[j]] != 0) {
                    cur = j;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans.push_back(i-start);
                start = i;
                cur = start;
            }
        }
        mp[str[i]]--;
    }
    ans.push_back(str.length()-start);
    if (!ans.empty()) {
        cout << ans[0];
    }
    for (int i = 1; i < ans.size(); ++i)
        cout << " " << ans[i];

    return 0;
}

