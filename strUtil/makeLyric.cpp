//
// Created by Lenovo on 2020/9/16.
//

//分离上下行歌词 取上行的歌词
#include <iostream>
#include <vector>

using namespace std;

bool isBlank(const string &s) {
    for (auto i:s) {
        if (i != ' ')return false;
    }
    return true;
}

int isEnglish(const string &s) {
    int i = 0;
    while (isblank(s[i]))i++;
    while(s[i]=='\241')i++; //特殊的空格
    if (isalpha(s[i]))return 1;
    return 0;
}

void makeLyric() {
    string s;
    int cnt = 0;
    vector<string> ans;
    printf("输入歌词，上行日语，下行中文，可以把日语分离出来，格式很重要\n");
    printf("输入 eof 代表结束\n");
    while (getline(cin, s)) {
        if (isBlank(s))continue;
        if (s == "eof")break;

        if (isEnglish(s))ans.push_back(s);

    }
    for (const string &ss:ans) {
        cout << ss << "\n";
    }
}
