class Solution {
public:

    static bool compare(const vector<int> v1,const vector<int> &v2)
    {
        // 身高的高的 在前面吗 
        return v1[0]>v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret;
        sort(people.begin(),people.end(),compare);
        for(const auto& temp:people)
        {
            int flag = 0,count = 0;
            if(ret.empty())
            {
                // 至少 第一个人
                ret.push_back(temp);
                continue;
            }
            // 对于每个人 他都要看看 他之前放下的人里面 有没有比他高的 
            // 比如需要三个  找到了 三个  就在这三个后面插入 
            for(auto it = ret.begin();it != ret.end();++it)
            {
                // 比他高的 人的个数  符合
                if(count == temp[1])
                {
                    // 插入这个人
                    ret.insert(it,temp);
                    flag = 1;
                    break;
                }
                // 身高 更高的人多了 
                if((*it)[0] >= temp[0]) ++count;
            }
            // 没有找到 那么多 比他身高 高的  
            if(!flag)   ret.push_back(temp);
        }
        return ret;
    }
};
