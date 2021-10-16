
// 0 p x y：将可重集 p 中大于等于 x 且小于等于 y 的值放入一个新的可重集中（新可重集编号为从 2 开始的正整数，是上一次产生的新可重集的编号+1）。
// 1 p t：将可重集 t 中的数放入可重集 p，且清空可重集 t（数据保证在此后的操作中不会出现可重集 t）。
// 2 p x q：在 p 这个可重集中加入 x 个数字 q。
// 3 p x y：查询可重集 p 中大于等于 x 且小于等于 y 的值的个数。
// 4 p k：查询在 p 这个可重集中第 k 小的数，不存在时输出 -1。

#include <cstdio>
#define ll long long
#define ls tree[rt].l
#define rs tree[rt].r
int n,m;
int c = 1;
int T[200005];

int cnt;
struct node{
    ll val;
    int l,r;
}tree[400005 << 5];

int Q(int &x) {if(x == 0) x = ++cnt;}

void pushup(int rt){
    tree[rt].val = tree[ls].val + tree[rs].val;
}

int build(int l,int r){
    int rt = ++cnt;
    if(l == r){
        scanf("%lld",&tree[rt].val);
        return rt;
    }
    int mid = l + r >> 1;
    ls = build(l,mid);
    rs = build(mid + 1,r);
    pushup(rt);
    return rt;
}

int spilt(int Q,int l,int r,int L,int R){
    int rt = ++cnt;
    if(l == L && r == R){
        tree[rt] = tree[Q];
        tree[Q].val = tree[Q].l = tree[Q].r = 0;
        return rt;
    }
    int mid = l + r >> 1;
    if(R <= mid){
        ls = spilt(tree[Q].l,l,mid,L,R);
    }else if(L > mid){
        rs = spilt(tree[Q].r,mid+1,r,L,R);
    }else{
        ls = spilt(tree[Q].l,l,mid,L,mid);
        rs = spilt(tree[Q].r,mid+1,r,mid+1,R);
    }
    pushup(rt);pushup(Q);
    return rt;
}

int merge(int x,int y){
    if(!x) return y;
    if(!y) return x;
    int rt = ++cnt;
    tree[rt].val = tree[x].val + tree[y].val;
    ls = merge(tree[x].l,tree[y].l);
    rs = merge(tree[x].r,tree[y].r);
    return rt;
}

void upload(int rt,int l,int r,int id,int C){
    tree[rt].val += C;
    if(l == r){
        return;
    }
    int mid = l + r >> 1;
    if(id <= mid){
        Q(ls);
        upload(ls,l,mid,id,C);
    }else{
        Q(rs);
        upload(rs,mid+1,r,id,C);
    }
}

ll query(int rt,int l,int r,int L,int R){
    if(l == L && r == R){
        return tree[rt].val;
    }
    int mid = l + r >> 1;
    if(R <= mid){
        return query(ls,l,mid,L,R);
    }else if(L > mid){
        return query(rs,mid+1,r,L,R);
    }else{
        return query(ls,l,mid,L,mid) + query(rs,mid+1,r,mid+1,R);
    }
}

int kth(int rt,int l,int r,ll k){
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    if(tree[ls].val >= k){
        return kth(ls,l,mid,k);
    }else{
        return kth(rs,mid+1,r,k - tree[ls].val);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    T[1] = build(1,n);
    int opt,p,x,y;
    for(int i = 1;i <= m;i++){
        scanf("%d%d",&opt,&p);
        if(opt == 0){
            scanf("%d%d",&x,&y); 
            T[++c] = spilt(T[p],1,n,x,y);
        }else if(opt == 1){
            scanf("%d",&x);
            T[p] = merge(T[p],T[x]);
        }else if(opt == 2){
            scanf("%d%d",&x,&y);
            upload(T[p],1,n,y,x);//加入y个x
        }else if(opt == 3){
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(T[p],1,n,x,y));
        }else{
            ll k;
            scanf("%lld",&k);
            if(query(T[p],1,n,1,n) < k) printf("-1\n");
            else printf("%d\n",kth(T[p],1,n,k));
        }
    }
    return 0;
}