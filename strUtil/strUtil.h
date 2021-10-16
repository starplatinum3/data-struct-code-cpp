//
// Created by Lenovo on 2021/2/23.
//

#ifndef DATASTRUCT_STRUTIL_H
#define DATASTRUCT_STRUTIL_H

#include <string>
#include <vector>

//std::vector<std::string> split(const std::string &s, const std::string &seperator);

#include <sstream>
#include <iostream>
#include <algorithm>

class StringUtils {
public:

//    static std::string reverse(const std::string &str) ;
//有问题
    static std::vector<std::string> split(const std::string &s, const std::string &seperator) {
        using std::vector;
        using std::string;
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


    static void splitTest(const std::string &str, std::string &symbol) {
        using std::string;
        using std::vector;
        using std::cout;
        using std::endl;
        vector<string> result;
        result = split(str, symbol);
        for (auto &basicString : result) {
            cout << atoi(basicString.c_str()) << endl;  // 把数字字符串转换为 数字
        }
    }

    static std::string getNums(const std::string &str) {
        std::string outStr;
        for (char ch:str) {
            if (isdigit(ch)) {
                outStr += ch;
            }
        }
        return outStr;
    }

//https://blog.csdn.net/how0723/article/details/80221691?depth_1-
    static bool endWith(const std::string &str, const std::string &tail) {
        return str.compare(str.size() - tail.size(), tail.size(), tail) == 0;
    }

    static bool startWith(const std::string &str, const std::string &head) {
        return str.compare(0, head.size(), head) == 0;
    }


    static std::vector<std::string>
    subStrsStartEndAll(std::string str, const std::string &start, const std::string &end) {
//# https://zhidao.baidu.com/question/2057789258998428427.html;
        std::vector<std::string> things;
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

            std::string subStr = str.substr(startPos, endPos - startPos) + end;

            things.emplace_back(subStr);

//        str = str[endPos + (end).size():];
            str = str.substr(endPos + (end).size());
        }


        std::vector<std::string> thingsFinal;
//# 这边不知道为什么会有不是以start开头的也被过滤进来了，想搞清楚太麻烦，还是
//    再过滤一次好了;
        for (const std::string &thing : things) {
            if (startWith(thing, start)) {
                thingsFinal.emplace_back(thing);
            }
//        if (thing.startwith(start))


        }

        return thingsFinal;

    }

//https://blog.csdn.net/how0723/article/details/80221691?depth_1-
    static void split(const std::string &strtem, const char a, std::vector<std::string> &res) {
        res.clear();
        std::string::size_type pos1, pos2;
        pos2 = strtem.find(a);
        pos1 = 0;
        while (std::string::npos != pos2) {
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
//string post;
    static void printEnglishWordsFromMixWords() {
        printf("input # to end\n");
        int cnt = 0;
        std::string a;
        getline(std::cin, a, '#');


        for (auto it = a.begin(); it != a.end(); it++) {
            if ((*it <= 'z' && *it >= 'a') || (*it <= 'Z' && *it >= 'A')) {
                if ((*(it - 1) <= 'z' && *(it - 1) >= 'a') || (*(it - 1) <= 'Z' && *(it - 1) >= 'A')) {
                    std::cout << *it;
                } else {
                    cnt++;
                    if (cnt >= 7) {
                        printf("\n");
                        cnt = 0;
                    }
                    std::cout << " " << *it;


                }

            }
        }
        printf("\n");
//    system("pause");

    }



//https://www.cnblogs.com/dingxiaoqiang/p/8228390.html

    static std::vector<std::string> split(const std::string &s, const char flag = ' ') {
//    using namespace std;

        std::vector<std::string> splitStrings;
        std::istringstream iss(s);
        std::string temp;

        while (getline(iss, temp, flag)) {
            splitStrings.push_back(temp);
        }
        return splitStrings;
    }


    static int
    sum(const std::string &listStr = "10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10") {
        std::vector<int> v = strToVector(listStr);
//    vector<int>vaa;
        int sum = 0;
        for (int val:v) {
            sum += val;
        }
        return sum;
    }


    static std::vector<int>
    strToVector(const std::string &listStr = "10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10") {
        std::vector<std::string> strVector = split(listStr, ' ');
        std::vector<int> intVector;
//    储备
        intVector.reserve(strVector.size());
        for (const auto &val:strVector) {
            intVector.emplace_back(stoi(val));
        }
        return intVector;
    }

    static std::string reverse(std::string str);
};


#endif //DATASTRUCT_STRUTIL_H
