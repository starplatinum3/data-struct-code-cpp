#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int post[31], mid[31];
queue<int> q;
vector<int> v;
//ac
struct node {
    int l, r;
} t[31];

int build(int postl, int postr, int midl, int midr) {
    int root, pos, i;
    if (postr - postl == 0)//若长度为1，则为叶节点
        return postl;
    if (postr - postl < 0)//post post
        return -1;
    root = postr;//post 后续
//mid、 mid
    for (i = midl; i <= midr; i++)
        if (post[root] == mid[i])// 左边根 右边
        {//mid left right root
            // printf("%d==post[root],root==%d\n",post[root],root);
            pos = i;
            break;
        }
    //  printf("after  postr ==%d==postl-pos-midl-1\n",postl+pos-midl-1,midl);
    t[root].l = build(postl, postl + pos - midl - 1, midl, pos - 1);
    // pol pol +pos-mil-1 , ml, pos-1
    t[root].r = build(postl + pos - midl, postr - 1, pos + 1, midr);
    //post post mid mid
    // pol+pos-mil, por-1,pos+1,mr
    return root;
}

void printtree(int n) {
    int temp;
    q.push(n);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        v.push_back(post[temp]);//post post

        if (t[temp].l != -1)
            q.push(t[temp].l);//t  tree

        if (t[temp].r != -1)
            q.push(t[temp].r);


//        if (t[temp].l!=-1)  
//            q.push(t[temp].l);
//t  tree
//            镜像 所以 l在后面  

    }
}

int main() {
    int n, i;
    cin >> n;


    for (i = 0; i < n; i++) {
        t[i].l = t[i].r = -1;
        cin >> post[i];//后
    }

    for (i = 0; i < n; i++)
        cin >> mid[i];//mid


    build(0, n - 1, 0, n - 1);
    printtree(n - 1);
    for (i = 0; i < v.size(); i++) {
        if (i == 0) {
            printf("%d", v[i]);
        } else {
            printf(" %d", v[i]);
        }
    }

    return 0;
}// ac
