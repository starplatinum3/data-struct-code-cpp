#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void printArr(	unsigned long int arr[],int len){
	for(int i=0;i<len;i++){
//		printf("%ld ",arr[i]);
		printf("%lu ",arr[i]);
	}
		printf("\n");
}
int main(void) {
	int i;
	int n;
	int j;
	int b[10];
	unsigned long int x;
	unsigned long int re;
	unsigned long int max;
	map<char, unsigned long int> m;
	unsigned long int a[10];
	//vector<string> s;
	for (i = 0; i<10; i++) {
		m[i + 'A'] = 0;
		b[i]=0;
	}

	cin >> i;
//    多少个

	for (n = 0; n<i; n++) {
		string temp;
		cin >> temp;
		//s.push_back(temp);
		x = 1;
//        字符有了
		b[temp[0]-'A']=1;
		for (j = temp.size() - 1; j >= 0; j--) {

			m[temp[j]] += x;
			//a[temp[j]-'A']+=x;
			x = x * 10;
//			个位 10位 
		}
		x = 1;
	}

for( auto val:m){
	printf("%lu ",val);
}
printf("\n");
	for (i = 0; i<10; i++) {
		a[i] = m[i + 'A'];
//		映射的数字 
	}
//	https://blog.csdn.net/dxz935/article/details/81592585
	printf("printArr\n");
	printArr(a,10);

	j=0;
	max=a[0];
	for(i=0; i<10; i++) {
		if(b[i]==0&&a[i]<max) {
			j=i;
			max=a[j];
//			最大的 
		}
	}
	a[j]=0;

	sort(a, a + 10);
	re = 0;
	for (i = 0; i<10; i++) {
		re += a[i] * i;
	}
	cout << re << endl;

}
//————————————————
//版权声明：本文为CSDN博主「dxz935」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/dxz935/article/details/81592585
