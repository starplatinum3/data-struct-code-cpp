
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            // 为什么要-1  
            // 5 -1 ）%
            int x = (num - 1) % n;
             cout<<"num: "<<num<<endl;
            cout<<"x: "<<x<<endl;
            nums[x] += n;
              cout<<"nums[x]: "<<nums[x]<<endl;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-d-mabl/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。