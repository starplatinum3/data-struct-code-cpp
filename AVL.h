//
// Created by Lenovo on 2021/3/3.
//

#ifndef DATASTRUCT_AVL_H
#define DATASTRUCT_AVL_H

typedef struct AVLNode *PtrToAVLNode;

struct AVLNode {
    int Key;
    PtrToAVLNode Left;
    PtrToAVLNode Right;
    int Height;
};


//struct AVLNode {
//    int Key;
//    PtrToAVLNode Left;
//    PtrToAVLNode Right;
//    int Height;
//};
typedef PtrToAVLNode AVLTree;

AVLTree Insert(AVLTree T, int Key);

void PostOrderPrint(AVLTree T); /* details omitted */
void InOrderPrint(AVLTree T);   /* details omitted */

int Max(int a, int b) ;

int GetHeight(AVLTree A) ;
AVLTree SingleRightRotation(AVLTree A) ;

AVLTree SingleLeftRotation(AVLTree A) ;
AVLTree DoubleRightLeftRotation(AVLTree A) ;

AVLTree DoubleLeftRightRotation(AVLTree A) ;
//https://blog.csdn.net/qq_40215528/article/details/84939945
#endif //DATASTRUCT_AVL_H
