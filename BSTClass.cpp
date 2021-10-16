
#include<bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    Node *l, *r;

    Node() {}

    Node(int val, Node *l, Node *r) {
        this->val = val;
        this->l = l;
        this->r = r;
    }

    Node(int val) {
        this->val = val;
        this->l = nullptr;
        this->r = nullptr;
    }
};

//struct Node{
//    int val;
//    Node * l,*r;
//};

Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->l = n->r = nullptr;
    return n;

}

Node *insert(int x, Node *root) {
    if (root == nullptr) {
        root = new Node(x);
//        root=newNode(x);
    } else {
        if (x < root->val)
            root->l = insert(x, root->l);
        else if (x > root->val)
            root->r = insert(x, root->r);

    }
    return root;
}

struct NodeAndStep {
    Node *node;
    int step;

    NodeAndStep(Node *node, int step) : node(node), step(step) {}
};

void printTreeLevelTra(Node *root) {
    queue<Node *> q;
//    queue<NodeAndStep*>q;
    q.push(root);
//    q.push(new NodeAndStep(root,0));
    printf("root : %d\n", root->val);
    while (!q.empty()) {
        Node *fr = q.front();
//        NodeAndStep * frontNodeAndStep=q.front();
        q.pop();
        printf("%d ", fr->val);
        if (fr->l) {
            q.push(fr->l);
        }
        if (fr->r) {
            q.push(fr->r);
        }
    }
}

int main() {
    Node *root = nullptr;
    for (int i = 0; i < 11; i++) {
        root = insert(i, root);
//       ×¢Òâ Òªroot=
    }
    printf("print tree\n");
    printTreeLevelTra(root);
}
