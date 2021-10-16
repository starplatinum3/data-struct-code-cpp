//1010 Radix (25 ��)
//https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
#include <iostream>
using  namespace std;

string  strNum2;

string str1,str2;
int tag;
long long int radix;
long long int num1;

long long int getNum(string str,long long int radix) {
//���ã����ջ���radix�����ַ���ת��strΪ��
//���ܻ�ܴ���longlong
	long long int sum=0;
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] <= '9')sum = sum * radix + (str[i] - '0');
		//ע�⡮0��-'9������a-z������
		else if(str[i]<='z')sum=sum*radix+(str[i]-'a'+10);
	}
	return sum;
}
long long int getRadix(long long int num1,string str,long long int start,long long int end) {
//��Ҫ�δ���
	if(start==end) {
		//�Ⱥŵ������ۣ����������ѭ��
		if(getNum(str,start)==num1)return start;
		else return 0;
	} else if(start<end) {
		long long int radix=(start+end)/2;
		//���ֲ���
		if(getNum(str,radix)==num1)return radix;
		//num2>num1��num2<0����ʾ���radixȡ�ù����ˣ���Ҫ��С
//        110 2,
		else if(getNum(str,radix)>num1||getNum(str,radix)<0)return getRadix(num1,str,start,radix);
		//num2<num1,˵��radixȡ�ñȽ�С������Ҫ������ȡ
		else return getRadix(num1,str,radix+1,end);
	}
	return 0;
}
int getMinRadix(string num2) {
//���ã��ҵ�num2����С����
//���磺num2������ȨֵΪbʱ����С��������b+1=12
	char max='0';
	for (int i = 0; i < num2.length(); ++i)
		if(num2[i]>max)max=num2[i];
	if (max <= '9')return max-'0'+1;
	else return max-'a'+11;
}


long long bin(     long long l,long long r) {
// int  bin(  int l,int r){

	while(l<=r) {
		if(l==r) {
			if(getNum(strNum2,l)==num1) {
				return l;
			} else {
				return 0;
			}
		}
		long long mid=(l+r)/2;
//              int  mid=(l+r)/2;
//         f(check(mid))
		long long tryNum=getNum(strNum2,mid);
//            if(check(mid)){
		if(tryNum==num1) {
			return mid;
		} else  if(tryNum>num1||tryNum<0) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	return 0;
}

long long getRadixBin(long long int num1,string str,long long int start,long long int end) {
	strNum2=str;

	long long  radix=	bin(start,end);
	return radix;
}
int main() {

	cin>>str1>>str2>>tag>>radix;

	//����tag=1��2������Ӧ����##
	if(tag==1) {
		num1=getNum(str1,radix);
	} else {
		num1=getNum(str2,radix);
		str2=str1;
	}
	//�����������
	if(num1==0&&str2=="0") { //����һ�£���������û���������
		cout<<"2";
		return 0;
	}
//    auto res=getRadix(num1,str2,getMinRadix(str2),num1+1);
	auto res=getRadixBin(num1,str2,getMinRadix(str2),num1+1);
	if(res==0) {
		cout<<"Impossible";
		return 0;
	}
	cout<<res;
	return 0;
}
