#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mid ((le+ri)>>1)
#define lson (node<<1)
#define rson (node<<1|1)
#define lc lson,le,mid
#define rc rson,mid+1,ri
#define sc node,le,ri
 
using namespace std;
const int maxm=1E5+10;
 
int n,q,ord,st[maxm*5][26],lazy[maxm*5],x,y,val,res[26];
void init(int node=1,int le=1,int ri=n),query(int node=1,int le=1,int ri=n),
     update(int node=1,int le=1,int ri=n),pushdown(int node,int le,int ri),
     pushup(int node),getans(int node=1,int le=1,int ri=n);
char str[maxm];
 
int main(){
    while(scanf("%d%d",&n,&q)!=EOF){
        scanf("%s",str);
        init();
        while(q--){
            scanf("%d%d%d",&x,&y,&ord);
            // x y 是表面数组的左右 边界
            memset(res,0,sizeof res);
            query();
 
            if(ord!=1){
                for(int i=25;i>=0;--i)
                if(res[i]){
                    y=x+res[i]-1,val=i;
                    // val 现在是字符的下标
                    // 现在是把val 赋值在25--0 的数组上面吗？
                    update();
                    x+=res[i];
                }
            }else{
                for(int i=0;i<26;++i)
                if(res[i]){
                    y=x+res[i]-1,val=i;
                    update();
                    x+=res[i];
                }
            }
        }
        getans();
        printf("\n");
    }
    return 0;
}
 
void pushdown(int node, int le, int ri){
    if(lazy[node]!=-1){
        lazy[lson]=lazy[rson]=lazy[node];
        memset(st[lson],0,sizeof st[lson]);
        memset(st[rson],0,sizeof st[rson]);
        st[lson][lazy[node]]=mid-le+1;
        st[rson][lazy[node]]=ri-mid;
        lazy[node]=-1;
    }
}
 
void pushup(int node){
    for(int i=0;i<26;++i)
    st[node][i]=st[lson][i]+st[rson][i];
}
 
void init(int node, int le, int ri){
    lazy[node]=-1;
    if(le==ri){
        memset(st[node],0,sizeof st[node]);
        st[node][str[le-1]-'a']=1;
    }else{
        init(lc);
        init(rc);
        pushup(node);
    }
}
 
void update(int node,int le,int ri){
    if(ri<x||le>y)return;
 
//  x y  线段树区间 
    if(x<=le&&ri<=y){
        lazy[node]=val;
        memset(st[node],0,sizeof st[node]);
        st[node][val]=ri-le+1;
    }else{
        pushdown(sc);
        update(lc);
        update(rc);
        pushup(node);
    }
}
 
void getans(int node, int le, int ri){
    if(le==ri){
        for(int i=0;i<26;++i)
        if(st[node][i]){
            printf("%c",i+'a');
            return;
        }
    }else{
        pushdown(sc);
        getans(lc);
        getans(rc);
    }
}
 
void query(int node,int le,int ri){
    if(ri<x||le>y)return;
 
    if(x<=le&&ri<=y){
        for(int i=0;i<26;++i)
        res[i]+=st[node][i];
    }else{
        pushdown(sc);
        query(lc);
        query(rc);
    }
}