//1010 Radix (25 ��)
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
// a
  string strNum1,strNum2;
int tag,rdx;
long long num1,num2;
//   long long getNum(string strNum,int radix){
  long long getNum(string strNum,  long long  radix){
    long long num=0;
  for(int i=0;i<strNum.size();i++){
      if(strNum[i]<='9')num=num*radix+strNum[i]-'0';
      else if(strNum[i]<='z') num=num*radix+strNum[i]-'a'+10;
  }
      return num;
}
int getMinRadix(string strNum){
//     int minRadix=INF;
    char   maxChar='0';
//     ��Ϊ������ 0 ���Ƶİ�
//     ����и� 9 , ���پ���10����, ��Ϊ�ж�һ��0 ,
    for(auto ch:strNum){
         maxChar=max(maxChar,ch);
//       else if(ch<='z') maxChar=max(base,ch-'a'+11);
        
    }
    if(maxChar<='9')return maxChar-'0'+1;
    
    return maxChar-'a'+11;
}

bool check(long long radix){
   return getNum(strNum2,radix)==num1;
}

// bin  �ǶԵ�
long long bin(     long long l,long long r){
// int  bin(  int l,int r){

    while(l<=r){
        if(l==r){
            if(getNum(strNum2,l)==num1){
                return l;
            }else{
                return 0;
            }
        }
        long long mid=(l+r)/2;
//              int  mid=(l+r)/2;
//         f(check(mid))
        long long tryNum=getNum(strNum2,mid);
//            if(check(mid)){
        if(tryNum==num1){
            return mid;
        }
      else  if(tryNum>num1||tryNum<0){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return 0;
}


//  long  long 
 long  long  getRadix(){
   long  long  minRadix=getMinRadix(strNum2);
//    long  long maxRadix=36;
//      36 �ͻ��һ������

//N1+1��Ϊʲô��N1+1�أ���N2ֻ��һλʱ�����С������޹أ����磺ֻҪ��������8��
//��ô8�������������16�����»���20�����£�����8(10�����£�����Ϊ�κλ�����0�η�����1�
//��N2����λ������ʱ�������ڶ�λ��С��1����ô����ΪN1+1ʱ��������ͱ�Ȼ����ڵ���N1+1�������ٴ��û�б�Ҫ�Ƚ��ˡ�

//n2 == 8 �����20 ����, Ҳ������� 
//n2 ������ 12 , n1=13 , ���� 14 , 14*1+2 , �����n2 ==10 ,��ô 14*1+0 ==14 ���� ���ڵ���N1+1��
//���� ��Ҫ���� �� radix ��� num2, ==num1 , ���ڻ���  ΪN1+1ʱ�������(num2) �ͱ�Ȼ����ڵ���N1+1 ��, �ǿ϶�����
//==num1 �� ���ԾͲ��ٳ�����
 
//��������������������������������
//��Ȩ����������ΪCSDN������Jcldcdmf����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/qq_37613112/article/details/91387345

      long  long maxRadix=num1+1;
//      ���� ���� �ͻ��., ���num1 �� 12, ��base
//      ���ǿ�����13 Ϊʲô? ֻ��һλ����ʱ����ܰ�
    long long radix=bin(minRadix,maxRadix);
    
//      int   minRadix=getMinRadix(strNum2);
//     int maxRadix=36;
//   int radix=bin(minRadix,maxRadix);
    
    
    return radix;
}

int main(){
   cin>> strNum1>>strNum2>>tag>>rdx;
  if(tag==1){
      num1=getNum(strNum1,rdx);
//       num2 �Ƕ������  strnum2 �Ƕ������
  }else{
      num1=getNum(strNum2,rdx);
      strNum2=strNum1;
  }
    int radix=getRadix();
    if(radix==0){
        printf("Impossible\n");
    }else{
//         printf("%lld\n",radix);
         printf("%d\n",radix);
//         ���� ����lld ����  ����û�д�
    }
    
}
