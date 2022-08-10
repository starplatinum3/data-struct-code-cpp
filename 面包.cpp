/*
20:46
总共n个，已有m个，a最重b最轻
已有的蛋糕数量已知
首先，要买最重和最轻。如果a,b在已有蛋糕重量中不是最重和最轻，则无法满足
设还可以烤k个蛋糕，k=n-m.

如果n < 2，pass，no

如果n >= 2：
m == 0, 则k = 2，yes
m == 1：
如果这个蛋糕=a或=b, k >= 1，yes
如果这个蛋糕b<蛋糕<a，我们需要自己做a,b，此时如果k>=2，yes
m >= 2:
如果所有蛋糕都在[b,a]，且有a也有b，yes
如果所有蛋糕都在(b,a)，我们要自己做a,b. 若k>=2，yes
以上，把n和m所有可能的情况都考虑到了，再加上a和b比较大小这种坑b条件
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
// https://www.nowcoder.com/test/question/done?tid=59411877&qid=1371123
    int maxCanMake, haveMake, wantBig, wantLittle;
    while(~scanf("%d%d%d%d",&maxCanMake,&haveMake,&wantBig,&wantLittle))
    {
        bool ok = 0;
        int restCanMake = maxCanMake-haveMake;
        // 还可以考多少个 k个
        if(wantBig < wantLittle) swap(wantBig,wantLittle); //**条件
        // 最大和最小的 
        // a 是大的
        if(maxCanMake >= 2)
        {
        // 小团一天最多可以烤n个蛋糕，每个蛋糕有一个正整数的重量。
        // 已经考好了 m个 
            if(haveMake == 0) ok = 1;
            // 可以
            else if(haveMake == 1)
            {
                int weight;
                scanf("%d",&weight);
                if((weight == wantBig || weight == wantLittle) && restCanMake >= 1) ok = 1;
                if(weight > wantLittle && weight < wantBig && restCanMake >= 2) ok = 1;
                // 他没有超标
            }
            else
            {
                int Max, Min;
                for(int i = 0;i < haveMake;i++)
                {
                    int weight;
                    scanf("%d",&weight);
                    if(i == 0) Min = weight, Max = weight;
                    Min = min(Min,weight);
                    Max = max(Max,weight);
                }
                if(Min == wantLittle && Max == wantBig) ok = 1;
                if(Min >= wantLittle && Max <= wantBig && restCanMake >= 2) ok = 1;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
