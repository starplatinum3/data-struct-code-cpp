//1058 A+B in Hogwarts (20 ·Ö)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a1,a2,a3,b1,b2,b3;
ll  c1,c2,c3;
const ll am=1e7;
//a 
int main(){
	scanf("%lld.%lld.%lld",&a1,&a2,&a3);
		scanf("%lld.%lld.%lld",&b1,&b2,&b3);
		c3=(a3+b3)%29;
		ll car=(a3+b3)/29;
		c2 =(a2+b2+car)%17;
		car=(a2+b2+car)/17;
//		c1 =(a1+b1+car)%am;
			c1 =(a1+b1+car);
//			²»ÄÜmod 
//		c1 =(a1+b1+car)%am;
printf("%lld.%lld.%lld",c1,c2,c3);
}
