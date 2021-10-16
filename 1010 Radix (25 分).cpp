//1010 Radix (25 分)
//https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
#include <iostream>
using  namespace std;

string  strNum2;

string str1,str2;
int tag;
long long int radix;
long long int num1;

long long int getNum(string str,long long int radix) {
//作用：按照基数radix，将字符串转化str为数
//可能会很大，用longlong
	long long int sum=0;
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] <= '9')sum = sum * radix + (str[i] - '0');
		//注意‘0’-'9’，和a-z不连续
		else if(str[i]<='z')sum=sum*radix+(str[i]-'a'+10);
	}
	return sum;
}
long long int getRadix(long long int num1,string str,long long int start,long long int end) {
//主要滴代码
	if(start==end) {
		//等号单独讨论，否则可能死循环
		if(getNum(str,start)==num1)return start;
		else return 0;
	} else if(start<end) {
		long long int radix=(start+end)/2;
		//二分查找
		if(getNum(str,radix)==num1)return radix;
		//num2>num1或num2<0都表示这个radix取得过大了，需要减小
//        110 2,
		else if(getNum(str,radix)>num1||getNum(str,radix)<0)return getRadix(num1,str,start,radix);
		//num2<num1,说明radix取得比较小，所以要往大了取
		else return getRadix(num1,str,radix+1,end);
	}
	return 0;
}
int getMinRadix(string num2) {
//作用：找到num2的最小基数
//例如：num2中最大的权值为b时，最小基数就是b+1=12
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

	//根据tag=1或2，作相应调整##
	if(tag==1) {
		num1=getNum(str1,radix);
	} else {
		num1=getNum(str2,radix);
		str2=str1;
	}
	//几种特殊情况
	if(num1==0&&str2=="0") { //试了一下，测试用例没有这种情况
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
