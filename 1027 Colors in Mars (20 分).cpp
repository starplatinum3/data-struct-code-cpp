
#include<bits/stdc++.h>
using namespace std;
//a
// vector<char>dui{'0','1','2'};
string dui="0123456789ABC";
string to13(int num){
//     int ans[111]; 
    if(num==0)return "00";
    vector<int>ans;
    for(;num;){
        ans.push_back(num%13);
        num/=13;
    }
    string res;
    for(int  val:ans){
        res+=dui[val];
    }
    reverse(res.begin(),res.end());
    if(res.size()==1)res="0"+res;
    return res;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"#"<<to13(a)<<to13(b)<<to13(c);
}
