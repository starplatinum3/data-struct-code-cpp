#include<bits/stdc++.h>
using namespace std;
//  写 11 样例4 过不了
const int MAX_TERM_CNT=21111;
//样例1 错的 我错了
struct Term{
    double coefficient;
    int exponent;
    bool operator<(const Term &rhs) const{
        return exponent> rhs.exponent;
    }
    Term(){}
    
    Term(double _coefficient, int _exponent){
        coefficient=_coefficient;
        exponent=_exponent;
    }
}; 


struct Polynomial{
   int   termCnt=0;
    Term terms[MAX_TERM_CNT];
};

int termCnt=0;
 Polynomial pln1,pln2;
Polynomial read(){
   Polynomial pln;
     scanf("%d", &termCnt);
    pln.termCnt=termCnt;
     for(int i=0;i<termCnt;i++){
//          不用lf 读取 会出问题。 如果用 f 读取 是不行的
         scanf("%d%lf",&pln.terms[i].exponent,&pln.terms[i].coefficient);
     }
    return pln;
}


Term sumSameEx( Polynomial  productPolynomial , int &i){
    int exponent=productPolynomial.terms[i].exponent;
    double sumCoe=0;
    int j;
    for( j=i;j<productPolynomial.termCnt;j++){
            if(productPolynomial.terms[j].exponent==exponent){
                sumCoe+=productPolynomial.terms[j].coefficient;
            }else{
                break;
            }
        }
    i=j;
//     一段 ex 相等的都加起来 i 也往后变化
//     2 x^2 +3 x^2 + 2 x^2 +3 x^2 + 2 x^3 +3 x^3
//     第一个一定相同的 因为就是他自己 ， 第二个如果不同 ，
//     j 也已经++ 了，这时候i=j 就是第二个了
//     return sumCoe;
    return Term(sumCoe,exponent);
}


// 2x^2 +3x^3 )*( 2x^2+3x^3 )
// 2x^2  * 2x^2 +2x^2 *3x^3  ...
//  4x^4 ex+ex,  coefficient *coefficient
void product(){
    Polynomial productPolynomial;
    productPolynomial.termCnt=0;
    for(int i=0;i<pln1.termCnt;i++){
        for(int j=0;j<pln2.termCnt;j++){
              productPolynomial.terms[productPolynomial.termCnt]=Term(pln1.terms[i].coefficient*pln2.terms[j].coefficient,
                                                                      pln1.terms[i].exponent+pln2.terms[j].exponent);
            
//             productPolynomial.terms[productPolynomial.termCnt].exponent=pln1.terms[i].exponent+pln2.terms[j].exponent;
//               productPolynomial.terms[productPolynomial.termCnt].coefficient=pln1.terms[i].coefficient*pln2.terms[j].coefficient;
            productPolynomial.termCnt++;
        }
    }
    Polynomial sorted;
    sort(productPolynomial.terms,productPolynomial.terms+productPolynomial.termCnt);
    for(int i=0;i<productPolynomial.termCnt;){
//       double   coefficien= sumSameEx(productPolynomial,i);
  Term t=sumSameEx(productPolynomial,i);
        sorted.terms[sorted.termCnt]=t;
        
//         sorted.terms[sorted.termCnt].coefficient=coefficient;
//           sorted.terms[sorted.termCnt].exponent=exponent;
 sorted.termCnt++;
    }
    
    printf("%d",sorted.termCnt);
    for(int i=0;i<sorted.termCnt;i++){
        if(sorted.terms[i].exponent!=0)
        printf(" %d %.1lf",sorted.terms[i].exponent,sorted.terms[i].coefficient);
    }
    
}


 int main(){
     pln1=read();
     pln2=read();
      product();
//      scanf("%d", &termCnt);
//      for(int i=0;i<termCnt;i++){
//          scanf("%f%d",)
//      }
     
     
 }
