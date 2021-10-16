#include<stdio.h>

int main(){
//	int x=0, y=0, z=0;
//z = (x==1) && (y=2);
//printf("%d ", y);

//int i=10;
//long long t = sizeof(i++);
//printf("%d", i);

//int a=(double)(10/4*4);
//printf("%d\n",a);

int i,x,y;	
i=x=y=0;
do {
	++i;
	if ( i%2 ) 
		x+=i, 
	i++;
	y +=i++;
} while ( i<=7 );
printf("%d %d %d", i, x, y);

} 


