//线段树数组修改 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100005;

int A[maxn];
int B[maxn];
int Tree[maxn<<2]; //线段树需要四倍的
int Lazy[maxn<<2]; //lazy标记
int n,m,Case;
//上推数据
void Pushup(int rt)
{
  Tree[rt] = Tree[rt*2+1]+Tree[rt*2];	
} 
void Pushdown(int rt,int ln,int rn)
{
	if(Lazy[rt])
	{
		Lazy[rt*2]+=Lazy[rt];
		Lazy[rt*2+1]+=Lazy[rt];
		
		Tree[rt*2]+=Lazy[rt]*ln;
		Tree[rt*2+1]+=Lazy[rt]*rn;
		Lazy[rt]=0; //标记删除 
	}
}
//区间修改 
// rt root
void updata(int L,int R,int l,int r,int rt,int D) //更新数据
{
  if(l>=L&&r<=R)
  {
    //   D 数据
    // 这是加法吧
   Tree[rt]+=D*(r-l+1);
   Lazy[rt]+=D;
   return ;	
  }	
  int mid = (l+r)>>1;
  //下推lazy结点 
  Pushdown(rt,mid-l+1,r-mid);
    // 左边有几个 右边有几个
  if(L<=mid) 
  updata(L,R,l,mid,(rt<<1),D);
//   左边区间 搞一搞
  if(R>mid) updata(L,R,mid+1,r,(rt<<1)+1,D);
  //   右边区间 搞一搞
  Pushup(rt);
} 

int Query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return Tree[rt];
	}
	int mid = (r+l)>>1;
	Pushdown(rt,mid-l+1,r-mid);
	int ans = 0;
	if(L<=mid) ans+=Query(L,R,l,mid,rt*2);
	if(R>mid) ans+=Query(L,R,mid+1,r,rt*2+1);
	return ans; 
}
// https://blog.csdn.net/rwrsgg/article/details/109003188
int main()
{
 int Choice;
 scanf("%d",&Case);
//  cin>>n>>m;
 scanf("%d%d",&n,&m);
//  给出一个长度为 n 的数组 {A_i}，由 1 到 n 标号
 memset(A,0,sizeof(A));
 memset(A,0,sizeof(B));
 memset(A,0,sizeof(Tree));
 memset(A,0,sizeof(Lazy));
 for(int i = 1;i<=n;i++)
 {
 scanf("%d",&A[i]);
 updata(i,i,1,n,1,A[i]);
//  线段树的话 A 本身应该没有被改吧 不知道啊
//  区间 i--i 。。。 + A[i]
 }
 for(int i = 0;i<m;i++)
	{
		// cin>>Choice;
        scanf("%d",&Choice);
		if(Choice==1)
		{
			int l,r,d;
			// cin>>l>>r>>d;
            scanf("%d%d%d",&l,&r,&d);
            // n 表面数组长度
			updata(l,r,1,n,1,d);
            // l r 区间 +d 
            // l r :  1 n 
            // 不知道这里为什么不会超时 
            // 保证 1<=n,m<=10^5。 ，1<=l<=r<=n
            // 应该是可以造出 10e10 的数据的
            // 这样就超时了 应该是数据不这样给吧

			// for(int j = l;j<=r;j++)
			// A[j]+=d;

        
            //   线段树的话 A 本身应该没有被改吧 不知道啊
            // 应该是 看这里都这样 要重新改过的
		}
		if(Choice==2)
		{
			int l1,r1,l2,r2;
			// cin>>l1>>r1>>l2>>r2;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			for(int j = 0;j<=r2-l2;j++)
			 {
			 int u = A[l2+j]-A[l1+j];
            //  差值 
           
			//  B[l1+j]=A[l2+j];   

            //  为什么不是像 题目里给的这样写
            //  换句话说先对 0<=i<=r_2-l_2 执行 B_i=A_(l_2+i)，
            // 再对 0<=i<=r_1-l_1 执行 A_(l_1+i)=B_i，其中 {B_i} 
            // 为一个临时数组。    
            // 不过实际上好像一样，只是B 下标不是从0 开始了，所以要开的大一点
            // 但这多余的内存空间相对于线段树 是小case   
			 updata(l1+j,l1+j,1,n,1,u);
              // 原始的地方加上差值
            //  l1+j 这个点 
			 }
			//  for(int j = l1;j<=r1;j++)   //注意一定要先保存进一个临时数组，不然不能成功修改 
			//  A[j] = B[j];
		}
		if(Choice==3)
		{
			int l,r;
			// cin>>l>>r;
            scanf("%d%d",&l,&r);
            // 应该是主要是求和这里需要线段树 不然的话 前面的算法不会超时的
			printf("%d\n",Query(l,r,1,n,1));
		}
	}
	return 0;
} 
