
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = T.size(),count = 0;
        vector<int> dp(size,0);
        stack<int> s;
        for(int i=0;i<size;++i)
        {
            // 一直找 s 里面的东西
            printf("对于每一个数 都去搞个单调栈 来看 %d \n",T[i]);
            printf("栈里放进去 下标\n");
            while(!s.empty())
            {
                int  stTopVal= T[s.top()];
                if(stTopVal>= T[i]){
                    printf("栈顶的 东西 %d 比i位置的东西大了 %d \n",stTopVal,T[i]);
                    printf("那么就退出\n");
                     break;
                   }
                dp[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return dp;
    }
};


int main(){
    // vector<int> dailyTemperatures= {1,2,3,4,5};
     vector<int> dailyTemperatures= {73,74,75,71,69,72,76,73};
    Solution solution = Solution();
  vector<int>  res=   solution.dailyTemperatures(dailyTemperatures);
  for(auto it:res){
      printf("%d ",it);
  }
}