#include <bits/stdc++.h>
using namespace std;
#define debug(a) (cout<<a<<endl)

// https://blog.csdn.net/qq_38677814/article/details/82314153
int pre[100];
int in[100];
int post[100];
int n;
void print(){
    for(int i=1;i<=n;i++){
        printf("%d%c",in[i],i==n?'\n':' ');
    }
}
bool ok=true;
void build(int begin_pre,int begin_in,int begin_post,int n){
    if(n==2) ok=false;
    // 2 个的话 就不一定是哪个了
    if(!n) return;
    if(n==1){
        in[begin_in]=pre[begin_pre];
        return;
    }
    int rt=pre[begin_pre];//根节点
    int r_rt=post[begin_post+n-2];//右子树根节点 后序的倒数第二个节点
    int i;
    for(i=1;;i++){//数据范围才30，爆搜吧
        if(pre[i]==r_rt) break;
    }
    int L=i-begin_pre-1;
    // 左子树的大小
    in[begin_in+L]=rt;
    int R=n-(L+1);
    build(begin_pre+1,begin_in,begin_post,L);
    build(begin_pre+L+1,begin_in+L+1,begin_post+L,R);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i];
    for(int i=1;i<=n;i++) cin>>post[i];
    build(1,1,1,n);
    if(ok){
        puts("Yes");
    }
    else puts("No");
    print();
    return 0;
}
