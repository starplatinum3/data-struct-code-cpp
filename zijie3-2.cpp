/*
����������λ�ϸ�ķ�����
��ȡ����ͬ�ַ���λ�ã�����ababa��a��λ��Ϊ��0��2��4����b��λ��Ϊ��1��3������ÿ��λ�������ö�̬�滮��⡣
�ַ�a��λ������Ϊarr����̬�滮���̣�
dp(i,j)��ʾ�ַ�a��i��λ�õ���j��λ�õ��ַ�Ҫȫ�����ڣ�����Ҫ����Ҫ���ٴν�����
1. i==jʱ����ʾһ���ַ������ý�����dp(i,j)Ϊ0��
2. i+1==jʱ����ʾ�����ַ���λ�����arr[j]-arr[i]��
3.���������dp(i,j) = dp(i+1,j-1) + arr[j]-arr[i] - (j - i)��

˼·:
����˼���µ�3��ת�ơ���Ϊ[i+1,j-1]֮���Ѿ�����һ�������ĶΣ������������߶������м俿�ģ�����
��ô���������Ĵ����϶���һ����Ȼ��ͷǳ�����
*/
#include<bits/stdc++.h>
using namespace std;
#define N 1005
int dp[N][N];//dp[i][j]��ʾ��i��ĳ���ַ�����ͬ�ĵ�j���ַ���Ϊһ�������εĻ���
char str[2005];//�ҿ���1005��Ȼ˵��Խ��,��������������

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
//                �ַ����±�λ�� 
                siz++;
                dp[siz][siz]=0;
            }
            
//            ����ַ��� size  
//            a ����Щλ���� 0 4 5
  char chHere= ch+'a';
  printf("%c �ַ���λ������Щ: \n",chHere);
  printf("siz %d\n",siz);
            for(int i=0;i<v.size();i++){
            	printf("%d ",v[i]);
			}
		
			printf("\n");
//			������λ�� ���������λ�� 
        for(int i=siz-1; i>=0; i--)
        {
            for(int j=i+1; j<siz; j++)
            {
//            	v ���ַ����е�λ�� 
//            	��������ַ� 
//i j ���ҵ��� ��һ�����ַ��� ���綼��a�� λ��
//a ������� 0 1 2 3 ������ 
//i j ������������Ҫ��λ����  v[j]-v[i] ������֮ǰ��λ�ã� 
//v[j]-v[i] �ó����� 0 4 5 ��Щ���� 
                int dis=v[j]-v[i]-(j-i);
//                ���ڵ������±����� 
//v[j]-v[i] �������ǵ�����  ����  
//�������� ��Ҫ����������(j-i) �����Ի��ƶ���ô�� dis=v[j]-v[i]-(j-i);
                printf("====\n");
                printf("j %d i %d\n",j,i);
                printf("v[j] %d v[i] %d\n",v[j],v[i]);
                printf("dis %d\n",dis);
                printMark(v,i,j);
                printMark(str,i,j);
                if(i+1!=j)
                    dis+=dp[i+1][j-1];
                dp[i][j]=min(dp[i][j], dis);
//                m �������Ĵ��� ����ٵĻ� ���ϱ�׼ ���Ǹ������ֵ 
                if(dp[i][j]<=m) ans=max(ans, j-i+1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

	



