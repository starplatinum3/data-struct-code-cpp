#include <iostream>
#include <vector>
using namespace std;
const int N = 30+5;
int Pre[N],Post[N],n;
vector<int> In;
bool flag=true;
void build(int prst,int pred,int post,int poed){
    if(prst==pred){//�ﵽ�˼���ϸ�ֵ���ֹ����
        In.push_back(Pre[prst]);
        return;
    }
    if(Pre[prst]==Post[poed]){
        int i=prst;
//        poed-1 ��һ�� post end
//Ҫ��pre �����ҵ��� ��һ��root һ��������
        while(i<=pred&&Pre[i]!=Post[poed-1])i++;
//        ֻ���ų��������ڵ�root
        if(i-prst==1)//��ʱ���δ����ֵ����������ȫλ��������Ҳ������ȫλ��������
            flag = false;
//        https://kdocs.cn/l/cl8T4EvY8Gin
//        [��ɽ�ĵ�] ǰ�����Ψһ����.xlsx
        build(prst+1,i-1,post,post+i-prst-1-1);//������
        In.push_back(Pre[prst]);
        build(i,pred,post+i-prst-1,poed-1);//������
    }
}

//��֪ǰ��ͺ������ж϶������Ƿ�Ψһ�����Ψһ�������������Ľ����
// �����Ψһ���������һ�����������Ķ�������������������
//ǰ��1��2��3��4��6��7��5

//����2��6��7��4��5��3��1
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
