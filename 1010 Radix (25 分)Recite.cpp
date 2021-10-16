//1010 Radix (25 分)
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
//     因为不会有 0 进制的吧
//     如果有个 9 , 至少就是10进制, 因为有多一个0 ,
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

// bin  是对的
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
//      36 就会错一部分了

//N1+1。为什么是N1+1呢？当N2只有一位时，其大小与基数无关，例如：只要基数大于8，
//那么8这个数不管是在16进制下还是20进制下，都是8(10进制下），因为任何基数的0次方都是1嘛；
//当N2有两位或以上时，倒数第二位最小是1，那么基数为N1+1时，这个数就必然会大于等于N1+1，所以再大就没有必要比较了。

//n2 == 8 如果是20 进制, 也是满足的 
//n2 举例子 12 , n1=13 , 基数 14 , 14*1+2 , 如果是n2 ==10 ,那么 14*1+0 ==14 所以 大于等于N1+1，
//我们 需要的是 从 radix 算出 num2, ==num1 , 现在基数  为N1+1时，这个数(num2) 就必然会大于等于N1+1 了, 那肯定不能
//==num1 了 所以就不再尝试了
 
//————————————————
//版权声明：本文为CSDN博主「Jcldcdmf」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/qq_37613112/article/details/91387345

      long  long maxRadix=num1+1;
//      上限 错了 就会错., 如果num1 是 12, 那base
//      就是可能是13 为什么? 只有一位数的时候可能吧
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
//       num2 是二分算的  strnum2 是二分算的
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
//         这里 不用lld 都行  样例没有错
    }
    
}
