//
// Created by Lenovo on 2020/10/22.
//
#include <string>
#include <iostream>
void putComma(){
    using namespace std;
    string codeStr;
    cout<<"input a  code string ,we make some commas to make it more clear\n";
    cin>>codeStr;
    int cnt=0;
    for(char ch:codeStr){
        cnt++;
        if(cnt==4){
            cout<<ch<<",";
            cnt=0;
        }
        else cout<<ch;

    }
}