#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

TNode* init_TNode(int value)
{
    TNode  *new_node = (TNode*)malloc(sizeof(TNode));
    new_node->value=value;
    new_node->left = new_node->right = NULL;
    return new_node;
}
