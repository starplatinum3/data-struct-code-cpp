/*dp[i]指口袋体积为i时，共有几种方法
  对于所有物品进行遍历，该物体体积为volume[i]
*/
//用滚动数组法,每次状态转移仅仅根据前一行数组决定，故选择用一维数组
#include<cstdio>
int volume[21];
int dp[41];

int main()                                
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for (int i = 1; i<=n; i++)        //输入物品的体积
            scanf("%d", &volume[i]);
        for(int i = 1; i<=n; i++)    //对于所有物品进行遍历，该物体体积为volume[i]
        {
            for(int j = 40; j>=volume[i]; j--)    //j>=volume[i]因为dp[j]只能从0~40-volume[i]的状态转移而来
            {
                // j-volume[i]的空间被另外的东西填满 就行了,j-volume[i]要填满,已经有这个dp获得了
                dp[j] += dp[j-volume[i]]; //如果dp[j]已经有了x种方法，而dp[j-volume[i]]也有y种方法
            }                   //那么由于物体i的存在，对于体积为j的口袋，又能多出dp[j-volume[i]]种方法
            //例如j=20，volume=10，而有5种方法能装满体积为10的口袋，那么只要有体积为10的物体就一定多出5种装满体积为20的口袋的方法
            // 也就是 10口袋和这个10体积的物体放在一起 装满了 20 体积
            dp[volume[i]]++;//显而易见，当口袋体积等于该物体体积时，必然有一种方法
        }             //而可能不止一个物体有这样的体积，所以每次碰到这个体积的物体，就做一次++运算
        printf("%d\n",dp[40]);
    }//while
    return 0;
}


// https://www.nowcoder.com/questionTerminal/9aaea0b82623466a8b29a9f1a00b5d35?toCommentId=1467409