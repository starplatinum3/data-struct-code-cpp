
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        auto pos = nums.begin();
        while(pos != nums.end())
        {
            // 是0的话 
            // !(*pos) 是true 说明 (*pos) 是0 
            if(!(*pos))
            {
                // https://blog.csdn.net/thorking01/article/details/103764993
                // 删掉0 之后的位置
                // 1 2 3 4 0 5 6 
                // 删掉之后到 5 
                pos = nums.erase(pos);
                ++count;
            }
            else  ++pos;
        }
        for(int i=1;i<=count;++i)   nums.push_back(0);
    }
};



int main(){
    // vector<int> dailyTemperatures= {1,2,3,4,5};
     vector<int> dailyTemperatures= {73,74,75,71,69,72,76,73};
    Solution solution = Solution();
  solution.moveZeroes(dailyTemperatures);
//   for(auto it:res){
//       printf("%d ",it);
//   }
}