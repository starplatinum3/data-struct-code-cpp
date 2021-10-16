
#include<stdio.h>
#include<math.h>
int main(){
	for(int x=0;x<1111;x++){
//		x^4
		int t=pow(x,4)+7*x+4;
		if(t%243==0){
			printf("x: %d\n",x);
		}
	}
//	x: 184


	
} 
