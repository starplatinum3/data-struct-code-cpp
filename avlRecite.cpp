//1123 Is It a Complete AVL Tree (30 ·Ö)
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *l, *r;

    Node(int val) : val(val) {
        l = r = nullptr;
    }

};

// AVL ????????swap??
// ????????????????????
// ??????????????????????rr??
// ???a=t->r ??????
Node *right(Node *t) {
    Node *a = t->r;
    t->r = a->l;
    a->l = t;
    return a;
}

void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}

Node *left(Node *t) {
    Node *a = t->l;
    t->l = a->r;
    a->r = t;
    return a;
}

Node *rightLeft(Node *t) {
    t->r = left(t->r);
    return right(t);

}

Node *leftRight(Node *t) {
    t->l = right(t->l);
    return left(t);

}

int getH(Node *t) {
    if (t == nullptr) {
        return 0;
    }
    return max(getH(t->l), getH(t->r)) + 1;
}


Node *ins(int x, Node *t) {
    if (t == nullptr) {
        t = new Node(x);

    } else {
        if (x < t->val) {
            t->l = ins(x, t->l);
            int hl = getH(t->l);
            int hr = getH(t->r);
            printf("hl hr %d %d\n", hl, hr);
            if (hl - hr == 2) {
                if (x < t->l->val) {
                    t = left(t);
                } else {
                    t = leftRight(t);
                }
//				t=left(t);
            }

//			else {
//				t=leftRight(t);
//			}

//			if(x<t->l->val){
//				t=left(t);
//			}else{
//				t=leftRight(t);
//			}

        } else if (x > t->val) {

            t->r = ins(x, t->r);
            int hl = getH(t->l);
            int hr = getH(t->r);
            printf("hl hr %d %d\n", hl, hr);
            if (hl - hr == -2) {
//				t=right(t);
                if (x > t->l->val) {
                    t = right(t);
                } else {
                    t = rightLeft(t);
                }


//			} else {
//				t=rightLeft(t);
//			}



//			if(x>t->l->val){
//				t=right(t);
//			}else{
//				t=rightLeft(t);
//			}
            }
        }

    }
    return t;

}

Node* insRecite(int x,Node *t){
    if(t== nullptr){
        t=new Node(x);
    }else{
        if(x<t->val){
            t->l=insRecite(x,t->l);
            if(getH(t->l)-getH(t->r)==2){
                if(x<t->l->val){
                    t=left(t);
                } else{
                    t=leftRight(t);
                }
            }
        }
        else if(x>t->val){
            t->r=insRecite(x,t->r);
            if(getH(t->l)-getH(t->r)== -2){
                if(x>t->r->val){
                    t=right(t);
                } else{
                    t=rightLeft(t);
                }
            }
        }
    }
}
int sho[111];
vector<int> levPa;
int cnt[111];

void printV(vector<int> v) {
    int fir = 1;
    for (int val:v) {
        if (fir)fir = 0;
        else printf(" ");
        printf("%d", val);
    }
    printf("\n");
}

void lev(Node *t) {
    queue<pair<Node *, int>> q;
    q.push(make_pair(t, 0));
    while (!q.empty()) {
        auto fr = q.front();
        q.pop();
        int step = fr.second;
        Node *nod = fr.first;

        levPa.push_back(nod->val);

        cnt[step]++;
        if (nod->l) {
            q.push(make_pair(nod->l, step + 1));
        }
        if (nod->r) {
            q.push(make_pair(nod->r, step + 1));
        }

//		maxLev=max(maxLev,step);
    }

    printV(levPa);
//
//	printf("%d + %d = %d\n",cnt[maxLev],cnt[maxLev-1]
//	       ,cnt[maxLev]+cnt[maxLev-1]);

    int no = 0;
    for (int i = 0; cnt[i]; i++) {
        if (cnt[i] != sho[i]) {
            no = 1;
            break;
        }
    }
    if (no) {
        printf("NO");
    } else {
        printf("YES");
    }
}

//0 1 2 3 4
// 1 2 4 8 16..

int n;

#include "AVL.h"

void mainAVLTest() {
    AVLTree avlTree = nullptr;
    scanf("%d", &n);
    sho[0] = 1;
    for (int i = 1; i < 22; i++) {
        sho[i] = sho[i - 1] * 2;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        avlTree = Insert(avlTree, x);
    }

//    printf("lev\n");
//    lev(t);
}

void mainMyAVL() {


    Node *t = nullptr;
    scanf("%d", &n);
    sho[0] = 1;
    for (int i = 1; i < 22; i++) {
        sho[i] = sho[i - 1] * 2;
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        t = ins(x, t);
    }

    printf("lev\n");
    lev(t);
}

int main() {
    mainAVLTest();
}
