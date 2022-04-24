#include <string.h>
#include <stdio.h>

class Solution {
public:
    bool isUgly(int n) {
        while(n>0){
            if(n%2==0){
                n/=2;
            }
            // 6/2 
            printf("n %d\n", n);
            if(n==0){
                return true;
            }
            // 2
            if(n%3==0){
                n/=3;
            }
            printf("n %d\n", n);
              if(n==0){
                return true;
            }
             if(n%5==0){
                n/=5;
            }
            printf("n %d\n", n);
              if(n==0){
                return true;
            }
            // printf("n %d\n",n);
            if(n==1){
                 return true;
                // return false;
            }
        }
        return false;

    }
};


int main(){
    Solution solution= Solution();
    int testNum=14;
    bool res=solution.isUgly(testNum);
// bool res=solution.isUgly(6);
   printf("Solution %d ",res);
   return 0;
}
