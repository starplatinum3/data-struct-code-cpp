#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct date
{
    ll y,m,d;
}a,b;
int mtod[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool run(int y){return (y%4==0&&y%100!=0)||y%400==0;}
bool ok(date a){return a.y>0&&a.m>0&&a.m<13&&a.d<=(mtod[a.m]+(run(a.y)&&a.m==2));}
ll solve(date a)
{
    a.y--;
    ll ans=a.y/4-a.y/100+a.y/400+a.y*365+a.d;
    for(int i=1;i<a.m&&i<13;i++)ans+=mtod[i];
    if(a.m>2&&run(a.y+1))ans++;
    return ans;
}
int main()
{
//    cin>>a.y>>b.y>>a.m>>b.m>>a.d>>b.d;
 
    
    
     cin>>a.y>>a.m>>a.d;
      cin>>b.y>>b.m>>b.d;
    printf("You have lived %d days.\n",solve(b)-solve(a));
//    ll ca=solve(a),cb=solve(b);
//    if(!ok(a)||!ok(b)||cb<ca)cout<<"Are you Keadin me?";
//    else cout<<cb-ca+1;
}
