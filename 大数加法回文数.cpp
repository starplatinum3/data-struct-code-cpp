
#include<bits/stdc++.h>
using namespace std;

string add(string s){
    string ans=s;
    string  a=reverse(s.begin(),s.end());
    int carry=0;
    for(int i=s.length()-1;i>=0;i--){
        int tmp=s[i]-'0'+a[i]-'0';
        ans[i]=(tmp+carry)%10+'0';
        carry=(tmp+carry)/10;
    }
    if(carry>0){
        ans.insert(0,"1");
    }
    return ans;
}

int main(){
    string s,step;
    cin>>s>>step;
    string rev=reverse(s.begin(),s.end());
    if(s==rev){
        cout<<s<<"\n"<<0;
        return;
    }
    int i;
    for(i=1;i<=step;i++){
        s=add(s);
        string rev=reverse(s.begin(),s.end());
        if(s==rev){
            break;
        }
    }
    if(i<=step){
        cout<<s<<"\n"<<i;
    }else{
        cout<<s<<"\n"<<step;
    }
}