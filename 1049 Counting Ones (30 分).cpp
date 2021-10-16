#include <bits/stdc++.h>
using namespace std;
int   N ,total; 
void getOnes(int n, int m, int cnt) {
    if( n == 0 ) 
	    return;
    int a = n % 10;
    int b = n / 10;
    int c = cnt;
    int d = 1;
     printf("=======\n");
    while(c--) {
        d *= 10;
    }
//    left now right
       11110111
    printf("a 是末尾， b 是除了末尾，c 是位数，d是位数的补零，类似10000\n");
    printf("n m cnt %d %d %d\n",n,m,cnt);
    printf("a b  d %d %d %d \n",a,b,d); 
    if(a < 1) {
	
    	printf("a < 1\n");
    		printf("total += (%d)*%d;\n",b,d);
        total += b*d;
    }
    else if(a > 1) {
    	printf("a > 1\n");
    	printf("total += (b+1)*d;\n");
    	printf("total += (%d+1)*%d;\n",b,d);
        total += (b+1)*d;
    }
    else {
    	printf("a === 1\n");
    		printf("total += %d*%d+%d+1;\n",b,d,m);
        total += b*d+m+1;
    }
    
    m += a*d;
    printf("total m %d %d\n",total,m);
    getOnes(b, m, cnt+1);
}
int main(){
    cin>> N;
    getOnes(N, 0, 0);
    cout<< total;
    return 0;
}
