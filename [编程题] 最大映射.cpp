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
//    ���ٸ�

	for (n = 0; n<i; n++) {
		string temp;
		cin >> temp;
		//s.push_back(temp);
		x = 1;
//        �ַ�����
		b[temp[0]-'A']=1;
		for (j = temp.size() - 1; j >= 0; j--) {

			m[temp[j]] += x;
			//a[temp[j]-'A']+=x;
			x = x * 10;
//			��λ 10λ 
		}
		x = 1;
	}

for( auto val:m){
	printf("%lu ",val);
}
printf("\n");
	for (i = 0; i<10; i++) {
		a[i] = m[i + 'A'];
//		ӳ������� 
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
//			���� 
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
//��������������������������������
//��Ȩ����������ΪCSDN������dxz935����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/dxz935/article/details/81592585
