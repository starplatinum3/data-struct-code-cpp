#include<math.h>
#include<stdio.h> 
//https://www.zhihu.com/question/448024036
int main()

{

	float area,s,a,b,c;



//	scanf("%f,%f,%f\n",&a,&b,&c);
	scanf("%f,%f,%f",&a,&b,&c);

	s=(a+b+c)/2.0;

	area=sqrt(s*(s-a)*(s-b)*(s-c));

	printf("area=%f,%f,%f,%f,%f\n",area,a,b,c,s);

}
