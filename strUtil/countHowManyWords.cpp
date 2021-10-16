//
// Created by Lenovo on 2020/10/18.
//

#include <iostream>
#include <vector>

void countHowManyWords() {
    using namespace std;
    std::cout << "input words:" << "\n";
    cout << "when you want to stop , input %eof\n";
//    cout<<"乱码"<<"\n";
    std::string word;
//    std::vector<std::string> words;
    int cnt = 0;
    while (getline(cin, word)) {
        if (word.empty())continue;
        if (word == "%eof")break;
//        words.push_back(word);
        cnt++;
    }
    cout << "have " << cnt << " words" << "\n";
}
