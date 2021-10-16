#include <iostream>
#include <vector>
using namespace std;
const int N = 30+5;
int Pre[N],Post[N],n;
vector<int> In;
bool flag=true;
void build(int prst,int pred,int post,int poed){
    if(prst==pred){//达到了继续细分的终止条件
        In.push_back(Pre[prst]);
        return;
    }
    if(Pre[prst]==Post[poed]){
        int i=prst;
//        poed-1 下一个 post end
//要在pre 里面找到和 下一个root 一样的数字
        while(i<=pred&&Pre[i]!=Post[poed-1])i++;
//        只是排除掉了现在的root
        if(i-prst==1)//此时整段待划分的区域可以完全位于左子树也可以完全位于右子树
            flag = false;
//        https://kdocs.cn/l/cl8T4EvY8Gin
//        [金山文档] 前序后序唯一中序.xlsx
        build(prst+1,i-1,post,post+i-prst-1-1);//左子树
        In.push_back(Pre[prst]);
        build(i,pred,post+i-prst-1,poed-1);//右子树
    }
}

//已知前序和后续，判断二叉树是否唯一，如果唯一则输出中序遍历的结果。
// 如果不唯一则输出任意一颗满足条件的二叉树的中序遍历结果。
//前序：1、2、3、4、6、7、5

//后序：2、6、7、4、5、3、1
//https://www.cnblogs.com/jiading/articles/12547205.html
//7
//1 2 3 4 6 7 5
//2 6 7 4 5 3 1
int main()
{
//    https://blog.csdn.net/qq_37053885/article/details/100586969
    cin>>n;
    for(int i=0;i<n;i++)cin>>Pre[i];
    for(int i=0;i<n;i++)cin>>Post[i];
    build(0,n-1,0,n-1);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(int i=0;i<In.size();i++){
        cout<<In[i];
        if(i!=In.size()-1)cout<<" ";
        else cout<<endl;
    }
    return 0;
}
