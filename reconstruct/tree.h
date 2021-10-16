#ifndef TREE_H
#define TREE_H


typedef struct _node
{
   int value;
   struct _node *left;
   struct _node *right;
}TNode,*Tree;

TNode* init_TNode(int value);

#endif
