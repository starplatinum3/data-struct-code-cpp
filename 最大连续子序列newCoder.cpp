#include <iostream>
using namespace std;

int main()
{
    int sum, K, max;
    while(cin>>K)
    {
        if(K==0) break;
        sum = 0, max = 0;
        int nstart, start, nend, first, last;
        cin>>nstart;
        // 数字的开始 因为下面是 从 i=1 开始，所以 这个nstart相当于也是数字序列里的
        first = last = start =  max = sum = nend = nstart;
        // 数字 不是下标
        for(int i = 1; i<K; i++)
        {
            int tmp;
            cin>>tmp;
            if(sum<0){  //重新寻找最大连续子序列和
                sum = 0;
                start = tmp;  //记录序列的开始数
            }
            sum+=tmp;
            if(sum>max){  //当找到更大的连续子序列和，更新序列的开始和结尾
                max = sum;
                nstart = start;
                nend = tmp;
            }
            if(i==K-1) last = tmp;
        }
        if(max<0)  //当所有的数都是负数的时候，最大的和一定为负
            cout<<0<<" "<<first<<" "<<last<<endl;
        else
            cout<<max<<" "<<nstart<<" "<<nend<<endl;
            // 若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。
    }
    return 0;
}
// https://www.nowcoder.com/questionTerminal/afe7c043f0644f60af98a0fba61af8e7?f=discussion