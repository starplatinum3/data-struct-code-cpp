#include <iostream>
#include <stdlib.h>
using namespace std;
// https://www.nowcoder.com/test/question/done?tid=59443170&qid=1288003#summary
bool issu(int num)
{
    if (num == 2)
    {
        return true;
    }
    if (num % 2 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 3; i < num / 2 + 1; ++i)
        {
            if (num % i == 0)
            {
                return false;
                break;
            }
        }
    }
    return true;
}
int rand(int m, int n)
{
    int x = rand();
    if (x % n > m)
        return x;
}
int x;
bool is_hs(int a, int b)
{
    int temp;
    while (b)
    {
        temp = a;
        a = b;
        b = temp % b;
    }
    x = a;
    if (a == 1)
        return true;
    return false;
}
int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    // 随机函数表示生成一个介于到之间的随机整数（包括和）。现在想知道如果输入参数和，调用此随机
    int sumNumPrim = 0;
    for (int i = m; i <= n; i++)
    {
        if (issu(i))
        {
            sumNumPrim++;
        }
    }
    int allNumCnt = n - m + 1;
    while (!is_hs(sumNumPrim, allNumCnt))
    {
        sumNumPrim /= x;
        allNumCnt /= x;
    }

    cout << sumNumPrim << ' ' << allNumCnt << endl;

    return 0;
}