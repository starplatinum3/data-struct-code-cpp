#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
    
const int maxn = 1e7;
int tempp[maxn]={0}, tempt[maxn] = {0};
int main(){
    int sum = 0;
    string s;
    cin >> s;
    tempp[0] = (s[0] == 'P')? 1 : 0;
    for(int i = 1; i < s.size(); i++){
        tempp[i] = tempp[i - 1];
        if(s[i] == 'P') tempp[i]++;
    }
    for(int i=0;i<s.size();i++){
    	printf("%d ",tempp[i]);
	}
	putchar('\n');
	
	
    int len = s.size();
    tempt[len - 1] = (s[len - 1] == 'T')? 1 : 0;
    for(int i = s.size() - 2; i >= 0; i--){
        tempt[i] = tempt[i + 1];
        if(s[i] == 'T') tempt[i]++;
        else if(s[i] == 'A') 
		sum = (sum + tempp[i] * tempt[i] )% 1000000007;
//		i 前面有多少 p  后面有 t 
    }
    cout << sum;
    return 0;
}

