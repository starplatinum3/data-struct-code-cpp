#include<iostream>
#include<vector>
using namespace std;
#define MAX 202
bool graph[MAX][MAX]={0};
//https://blog.csdn.net/lianwaiyuwusheng/article/details/87871633
int judge(vector<int> &arr,int N)
{
    vector<bool>vis(N,0);
    for(int i=0;i<arr.size();++i){
        vis[arr[i]]=1;
        for(int j=0;j<arr.size();++j){
//        	点之间没有相连 
            if(i!=j&&!graph[arr[i]][arr[j]])return -1;//Not
        }
    }
    for(int j=1;j<=N;++j){
//    	为什么是arr0 
//应该是随便哪个都可以吧 因为每个地位都是相同的 
        if(!vis[j]&&graph[arr[0]][j]){//与顶点arr[0]相连的其他点j。
            int k;
            for(k=1;k<arr.size();++k){//j是否与其他点相连
                if(!graph[arr[k]][j])break;//不相连
            }
            if(k==arr.size())return 0;//不是最大
        }
    }
    return 1;
 
}
int main()
{
    freopen("test.txt","r",stdin);
    int Nv,Ne,a,b,M,K;
    scanf("%d %d",&Nv,&Ne);
    while(Ne--){
        scanf("%d %d",&a,&b);
        graph[a][b]=graph[b][a]=1;
    }
    scanf("%d",&M);
    while(M--){
        scanf("%d",&K);
        vector<int>arr;
        for(int i=0;i<K;++i){
            scanf("%d",&a);
            arr.push_back(a);
        }
        int x=judge(arr,Nv);
        if(x==1)printf("Yes\n");
        else if(x==-1)printf("Not a Clique\n");
        else if(x==0)printf("Not Maximal\n");
    }
    return 0;
}
