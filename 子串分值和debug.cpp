
#include <bits/stdc++.h>

#define int long long
const int N = 1e6 + 7;
using namespace std;
string s;
int dp[N];
int pos[30];

void printStr(int len) {
    for (int i = 0; i < len; i++) {
        putchar(s[i]);
    }
    putchar('\n');
}

set<string> split(const string &str) {
    set<string> strSet;
    for (int i = 0; i < str.length(); ++i) {
        for (int len = 1; len + i <= str.length(); ++len) {
            string sub = str.substr(i, len);
            strSet.insert(sub);
//            cout << sub << ",";
        }
//        putchar('\n');
    }
//    putchar('\n');
//    for (const string &sVal:strSet) {
//        cout << sVal << ",";
//    }
//    putchar('\n');
//    putchar('\n');
//    putchar('\n');
    return  strSet;
}
void more( const set<string>&big, set<string> small){
    printf("���sise:%d\n",big.size());
    for (const string &sVal:big) {
        cout << sVal << ",";
    }
    putchar('\n');
    printf("С��sise:%d\n",small.size());
    for (const string &sVal:small) {
        cout << sVal << ",";
    }
    putchar('\n');

    printf("���set��С��set �������Щ����\n");

    for (const auto& v:big){
        if(small.find(v)==small.end()){
            cout<<v<<",";
        }
    }
}
void split() {
    string string1 = "ababcc";
    set<string> set1 =  split(string1);
    set<string> set2=   split("ababc");
    more(set1,set2);
//    ababc abc babc bc c �����5 ������Ϊcû���ֹ�
}

signed main() {
    split();
    cin >> s;
    for (int i = 0; i < 30; i++) {
        pos[i] = -1;
    }
    dp[0] = 1;
    pos[s[0] - 'a'] = 0;
    for (int i = 1; i < s.size(); i++) {
        dp[i] = dp[i - 1] + i - pos[s[i] - 'a'];
//        ab
//        ֮ǰû���ֹ���bʹ�ù���ֵ������1 i����1
//        dp���ּ�¼����λ���������ܹ���
//        aba 3a ��֮ǰa ��0λ�� �������ĸ���
        printStr(i + 1);
        printf("dp[%d] :%d, dp[%d]:%d,i:%d,pos[%c]:%d\n", i, dp[i], i - 1, dp[i - 1], i, s[i], pos[s[i] - 'a']);
        pos[s[i] - 'a'] = i;
        printf("pos[%c]:%d\n", s[i], i);
        //cout<<dp[i]<<endl;
    }
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += dp[i];
    cout << res << endl;

    return 0;
}
//https://blog.csdn.net/qq_43461168/article/details/109146495

