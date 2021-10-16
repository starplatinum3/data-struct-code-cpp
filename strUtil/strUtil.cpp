//
// Created by Lenovo on 2020/10/22.
//

// codeThinking.cpp : 定义控制台应用程序的入口点。
//
//https://www.cnblogs.com/zpcoding/p/10645726.html
//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include<unordered_map>
#include "strUtil.h"
#include <algorithm>

using namespace std;

//实现to_string函数
// #include<iostream>
// #include<string>
// using namespace std;
// #define max 100
std::string to_String(int n)
{
    int m = n;
    char s[max];
    char ss[max];
    int i=0,j=0;
    if (n < 0)// 处理负数
    {
        m = 0 - m;
        j = 1;
        ss[0] = '-';
    }
    while (m>0)
    {
        s[i++] = m % 10 + '0';
        m /= 10;
    }
    s[i] = '\0';
    i = i - 1;
    while (i >= 0)
    {
        ss[j++] = s[i--];
    }
    ss[j] = '\0';
    return ss;
}

// https://www.cnblogs.com/smile233/p/8379802.html

// int main()
// {
//     cout << "请输入整数:";
//     int m;
//     cin >> m;
//     string s = to_String(m) + "abc";
//     cout << s << endl;
//     system("pause");
//     return 0;
// }


//有问题
vector<string> split(const string &s, const string &seperator) {
    vector<string> result;
    unsigned int posBegin = 0;
    unsigned int posSeperator = s.find(seperator);

    while (posSeperator != std::string::npos) {
        result.push_back(s.substr(posBegin, posSeperator - posBegin));//
        posBegin = posSeperator + seperator.size(); // 分隔符的下一个元素
        posSeperator = s.find(seperator, posBegin);
    }
    if (posBegin != s.length()) // 指向最后一个元素，加进来
        result.push_back(s.substr(posBegin));

    return result;
}

void splitTest(const string &str, string &symbol) {
    vector<string> result;
    result = split(str, symbol);
    for (auto & i : result) {
        cout << atoi(i.c_str()) << endl;  // 把数字字符串转换为 数字
    }
}

std::string getNums(const string &str) {
    string outStr;
    for (char ch:str) {
        if (isdigit(ch)) {
            outStr += ch;
        }
    }
    return outStr;
}

//https://blog.csdn.net/how0723/article/details/80221691?depth_1-
bool endWith(const string &str, const string &tail) {
    return str.compare(str.size() - tail.size(), tail.size(), tail) == 0;
}

bool startWith(const string &str, const string &head) {
    return str.compare(0, head.size(), head) == 0;
}


vector<std::string> subStrsStartEndAll(std::string str, const std::string& start, const std::string& end) {
//# https://zhidao.baidu.com/question/2057789258998428427.html;
    vector<std::string> things;
//# https://www.cnblogs.com/xingchuxin/p/10427391.html;
    int startPos, endPos, startAnotherPos, endAnotherPos;
    while (true) {
        startPos = str.find(start);
        if (startPos == -1)break;

        endPos = str.find(end);
        if (endPos == -1)break;
        while (true) {

//# https://blog.csdn.net/weixin33739523/article/details/93816000;
            startAnotherPos = str.find(start, startPos + 1);
//# 如果有不符合的字符串，比如说https:3,https:4.jar,3后面没有.jar，就
//    要把3的这个去掉;
//# 如果https后面还有个https，但是中间没有.jar，说明前面的https是不正
//    确的格式，要舍去;
            if (startAnotherPos == -1)
                break;
            if (startAnotherPos < endPos)
                startPos = startAnotherPos;
            if (startPos > endPos) {
                endAnotherPos = str.find(end, endPos + 1);
                endPos = endAnotherPos;
            } else
                break;
        }

        string subStr = str.substr(startPos, endPos - startPos) + end;

        things.emplace_back(subStr);

//        str = str[endPos + (end).size():];
        str = str.substr(endPos + (end).size());
    }


    vector<std::string> thingsFinal;
//# 这边不知道为什么会有不是以start开头的也被过滤进来了，想搞清楚太麻烦，还是
//    再过滤一次好了;
    for (const std::string& thing : things) {
        if (startWith(thing, start)) {
            thingsFinal.emplace_back(thing);
        }
//        if (thing.startwith(start))


    }

    return thingsFinal;

}

//https://blog.csdn.net/how0723/article/details/80221691?depth_1-
void split(const string &strtem, const char a, vector<string> &res) {
    res.clear();
    string::size_type pos1, pos2;
    pos2 = strtem.find(a);
    pos1 = 0;
    while (string::npos != pos2) {
        res.push_back(strtem.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = strtem.find(a, pos1);
    }
    res.push_back(strtem.substr(pos1));
}

//int _tmain(int argc, _TCHAR* argv[])
//{
//    string widths = "5 5 5 5 5 5 10 10 10 10 10 10 10 10 10 10 10 10 5 5 5 5 5 5 5 5";
//    string symbol = " ";
//
//    splitTest(widths,symbol);
//
//
//    system("pause");
//    return 0;
//}
//

//#include<bits/stdc++.h>
//using namespace std;
//string a;
void printEnglishWordsFromMixWords() {
    printf("input # to end\n");
    int cnt = 0;
    string a;
    getline(cin, a, '#');


    for (auto it = a.begin(); it != a.end(); it++) {
        if ((*it <= 'z' && *it >= 'a') || (*it <= 'Z' && *it >= 'A')) {
            if ((*(it - 1) <= 'z' && *(it - 1) >= 'a') || (*(it - 1) <= 'Z' && *(it - 1) >= 'A')) {
                cout << *it;
            } else {
                cnt++;
                if (cnt >= 7) {
                    printf("\n");
                    cnt = 0;
                }
                cout << " " << *it;


            }

        }
    }
    printf("\n");
//    system("pause");

}

//因为这里写了 const ，不能写 因为 reverse 是要 变化的
std::string StringUtils::reverse( std::string str) {
//    error: no matching function for call to 'swap(const char&, const char&)'
//    swap(*__a, *__b);
    std::reverse(str.begin(), str.end());
    return str;
}
