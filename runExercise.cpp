//
// Created by Lenovo on 2021/2/10.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int check(int y,int m){ // leap year
    return m == 2 && (y%400 == 0|| (y%4 == 0 && y%100 != 0));
}
signed main()
{
    int y = 2000;
    int m = 1;
    int d = 1;
    int yy = 2020;
    int mm = 10;
    int dd = 1;
    int week = 6-1;
    int res = 0;
    for( ; y <= yy ; y ++){
        int lim1 = (y == yy) ? mm : 12;
        for( ; m <= lim1; m ++){
            int lim2 = (y == yy && m == mm ) ? dd : days[m]+check(y,m);
            for( ; d <= lim2 ; d ++){
                week = (week)%7+1;
                res ++;
                if(week == 1 || d == 1){
                    res ++;
                }
            }
            d = 1;
        }
        m = 1;
    }
    cout<<week<<" "<<res<<endl;
    return 0;
}
