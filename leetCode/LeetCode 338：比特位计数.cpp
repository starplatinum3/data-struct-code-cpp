
#include <bits/stdc++.h>
using namespace std;
char *getHex(int intNum);

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i >> 1] + i % 2;
        return ret;
    }
};

//计算机原理实验里面抄来的代码
// 打印这块内存
typedef unsigned char *byte_pointer;
//这是 unsigned char * ，所以里面的东西应该是unsigned char
void show_bytes(byte_pointer start, int len)
{
    printf("你的机器里面内存的状态\n");
    int i;
    std::stack<unsigned char> st;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
        st.push(start[i]);
    }

    // 一个字节是8位,也就是两个4位
    printf(" H\n");
    std::cout << "下面是和上面相反的，如果机器是小端的，那下面的是正常顺序\n";
    while (!st.empty())
    {
        //        std::cout<<st.top();
        printf(" %.2x", st.top());
        st.pop();
    }
    std::cout << "H\n";
}

int getIndex(char *hex, char toFind)
{
    int len = strlen(hex);
    for (int i = 0; i < len; i++)
    {
        if (hex[i] == toFind)
        {
            return i;
        }
    }
    return -1;
}

/**
 * 把一个16进制str转换成二进制，打印出来，用“,”分隔开，比较看得清楚，每4个分隔一个
 * @param hexStr
 */
void printBinFromHexStr(std::string hexStr)
{
    const char *hexToBin[] = {"0000", "0001", "0010", "0011",
                              "0100", "0101", "0110", "0111",
                              "1000", "1001", "1010", "1011",
                              "1100", "1101", "1110", "1111"};

    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    int len = hexStr.size();
    //    printf("hex %s\n",hexStr);

    std::cout << "hex : 0x" << hexStr << "\n";
    printf("binary: ");
    for (int i = 0; i < len; i++)
    {
        char toFind = hexStr[i];
        if (isupper(toFind))
        {
            toFind = tolower(toFind);
        }
        //      std::cout<<"toFind: "<<toFind<<"\n";
        int index = getIndex(hex, toFind);
        //        std::cout<<"index: "<<index<<"\n";
        printf("%s ", hexToBin[index]);
    }
    printf("\n");
}

void printBin(int intNum)
{
    printf("int : %d\n", intNum);
    printBinFromHexStr(getHex(intNum));
}

// 打印int类型数字的内存
void show_int(int x)
{
    // 这里关键是把x 一个int 型的数的地址 转成unsigned char *型的，
    // 其他的如果是float型的地址，也可以转成unsigned char *型的，
    // 这样所有数据类型都可以用一个show_bytes函数查看内存了
    show_bytes((byte_pointer)&x, sizeof(int));
}

char *alloc_chars(int howMany)
{
    char *r;
    if (howMany <= 0)
        return NULL;                            //参数错误
    r = (char *)malloc(sizeof(char) * howMany); //申请内存空间，大小为n个int长度。
    return r;                                   //返回得到的整型数组的指针。
}

char *getHex(int intNum)
{
    char *s = alloc_chars(32);
    sprintf(s, "%x", intNum);
    return s;
}

void testVal(int val)
{
    printf("=====\n");
    if (val % 2 == 0)
    {
        printf("对于偶数和它右移1位的数字包含1的个数相同。\n");
    }
    int __builtin_popcount_val = __builtin_popcount(val);
    int __builtin_popcount_val_shelf1 = __builtin_popcount(val >> 1);
    printf("val %d\n", val);
    printf("val>>1 %d\n", val >> 1);
    printf("show int\n");
    //   show_int(val);
    printf("===++++++==\n");
    printf("val 本身\n");
    // 因为奇数会把最后的1 移动掉
    // val >>1
    // int : 1
    // hex : 0x1
    // binary: 0001 ,比如 这里最后的1  >>1 的话 就没有了
    printBin(val);
    printf("==========++++++==\n");
    printf("val >>1\n");
    printBin(val >> 1);
    printf("===++++++==-----\n");
    // printf("二进制  x 是啥 %x\n",val);
    printf("__builtin_popcount_val %d\n", __builtin_popcount_val);
    printf("__builtin_popcount_val_shelf1 %d\n", __builtin_popcount_val_shelf1);
}

int main()
{
    // vector<int> dailyTemperatures= {1,2,3,4,5};
    //  vector<int> dailyTemperatures= {73,74,75,71,69,72,76,73};
    Solution solution = Solution();
    vector<int> res = solution.countBits(3);
    for (auto it : res)
    {
        printf("%d ", it);
    }

    for (int i = 0; i < 3; i++)
    {
        testVal(i);
    }
}