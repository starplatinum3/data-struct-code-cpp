/*
先是上面那位老哥的分析：
提取出相同字符的位置，比如ababa中a的位置为（0，2，4），b的位置为（1，3）。对每个位置向量用动态规划求解。
字符a的位置数组为arr，动态规划过程：
dp(i,j)表示字符a第i个位置到第j个位置的字符要全部相邻，至少要用需要多少次交换。
1. i==j时，表示一个字符，不用交换，dp(i,j)为0；
2. i+1==j时，表示两个字符，位置相差arr[j]-arr[i]；
3.其他情况，dp(i,j) = dp(i+1,j-1) + arr[j]-arr[i] - (j - i)；

思路:
首先思考下第3种转移。因为[i+1,j-1]之间已经成了一个连续的段，所以左右两边都是往中间靠的，不管
怎么靠，交换的次数肯定都一样。然后就非常简单了
*/
#include<bits/stdc++.h>
using namespace std;
#define N 1005
int dp[N][N];//dp[i][j]表示第i个某种字符和相同的第j个字符成为一个连续段的花费
char str[2005];//我开了1005竟然说我越界,怀疑数据有问题

void printMark(const  vector<int>& vec,int mark1,int mark2){
	for(int i=0;i<vec.size();i++){
		if(mark1==i||mark2==i){
				printf("(%d) ",vec[i]);
		}else{
				printf("%d ",vec[i]);
		}
	
	}
		printf("\n");
}

void printMark(const string &vec,int mark1,int mark2){
	for(int i=0;i<vec.size();i++){
		if(mark1==i||mark2==i){
				printf("(%c) ",vec[i]);
		}else{
				printf("%c ",vec[i]);
		}
	
	}
		printf("\n");
}
int main()
{
    int m, len, ans=1;
    scanf("%s %d", str, &m);
    len=strlen(str);
    for(int ch=0; ch<26; ch++)
    {
        int siz=0;
        vector<int> v;
        memset(dp, 63, sizeof(dp));
        for(int i=0; i<len; i++)
            if(str[i]==(ch+'a'))
            {
                v.push_back(i);
//                字符的下标位置 
                siz++;
                dp[siz][siz]=0;
            }
            
//            这个字符的 size  
//            a 的那些位置是 0 4 5
  char chHere= ch+'a';
  printf("%c 字符的位置是哪些: \n",chHere);
  printf("siz %d\n",siz);
            for(int i=0;i<v.size();i++){
            	printf("%d ",v[i]);
			}
		
			printf("\n");
//			有三个位置 针对这三个位置 
        for(int i=siz-1; i>=0; i--)
        {
            for(int j=i+1; j<siz; j++)
            {
//            	v 是字符串中的位置 
//            	他后面的字符 
//i j 是找到了 这一样的字符的 比如都是a的 位置
//a 的里面的 0 1 2 3 。。。 
//i j 是他们现在想要的位置吗  v[j]-v[i] 是他们之前的位置？ 
//v[j]-v[i] 拿出的是 0 4 5 那些东西 
                int dis=v[j]-v[i]-(j-i);
//                所在的两个下标的相减 
//v[j]-v[i] 本来我们的相差的  距离  
//现在我们 想要变成这个距离(j-i) ，所以会移动这么多 dis=v[j]-v[i]-(j-i);
                printf("====\n");
                printf("j %d i %d\n",j,i);
                printf("v[j] %d v[i] %d\n",v[j],v[i]);
                printf("dis %d\n",dis);
                printMark(v,i,j);
                printMark(str,i,j);
                if(i+1!=j)
                    dis+=dp[i+1][j-1];
                dp[i][j]=min(dp[i][j], dis);
//                m 交换最多的次数 如果少的话 符合标准 我们更新最大值 
                if(dp[i][j]<=m) ans=max(ans, j-i+1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

	



