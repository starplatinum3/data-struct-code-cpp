#include <iostream>
using namespace std;

int main()
{
    int n;
    int num[1001];
    int sum[1001];
    while(cin>>n)
    {
        int tmpsum = 0, maxsum = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>num[i];
            sum[i] = num[i]; //初始化，所有数自成一个最大递增子序列
        }
        sum[0] = num[0];
        for(int i = 1; i<n; i++)
        {
            for(int j = i-1; j>=0; j--)
            {
                if(num[j]<num[i])   //符合递增子序列
                    sum[i] = max(sum[j]+num[i], sum[i]);
                    // 之前的序列里加上了这个数
            }
        }
        maxsum = sum[0];
        for(int i = 1; i<n; i++)
        {
            if(maxsum<sum[i]) maxsum = sum[i];
        }
        cout<<maxsum<<endl;
    }
    return 0;
}

// https://www.nowcoder.com/questionTerminal/dcb97b18715141599b64dbdb8cdea3bd