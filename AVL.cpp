//
// Created by Lenovo on 2020/10/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
int mainAVL() {
    int N, Key, i;
    AVLTree T = NULL;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &Key);
        T = Insert(T, Key);
    }

    printf("%d\n",T->Key);
    /*undefined reference to `PostOrderPrint(AVLNode*)'
    PostOrderPrint(T);
    InOrderPrint(T);*/

    return 0;
}

/* Your function will be put here */



int Max(int a, int b) {
    return a > b ? a : b;
}

int GetHeight(AVLTree A) {
    if (A == NULL)
        return 0;
    return A->Height;
}

AVLTree SingleRightRotation(AVLTree A) {
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;

    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Right), A->Height) + 1;

    return B;
}

AVLTree SingleLeftRotation(AVLTree A) {
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;

    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left), A->Height) + 1;
    return B;
}

AVLTree DoubleRightLeftRotation(AVLTree A) {
//    A->Right = SingleRightRotation(A->Right);
//    return SingleLeftRotation(A);

    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}


AVLTree DoubleLeftRightRotation(AVLTree A) {
//    修改了 本来是 left的
    A->Left = SingleRightRotation(A->Left);
//    return SingleRightRotation(A);
    return SingleLeftRotation(A);
}

//https://blog.csdn.net/qq_40215528/article/details/84939945
AVLTree Insert(AVLTree T, int X) {
    if (!T) {
        T = (AVLTree) malloc(sizeof(struct AVLNode));
        T->Key = X;
        T->Height = 1;
        T->Left = T->Right = NULL;
    } else if (X < T->Key) { //插入左子树
        T->Left = Insert(T->Left, X);
//        左子树 更加深
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
//            X 比左子树的值小，说明是在左子树的左边插入，说明要ll单旋转
            if (X < T->Left->Key) {
//                T=SingleRightRotation(T);
                T = SingleLeftRotation(T);
            } else
//                T=DoubleRightLeftRotation(T);
                T = DoubleLeftRightRotation(T);
        }
    } else if (X > T->Key) {
        T->Right = Insert(T->Right, X);
        if (GetHeight(T->Left) - GetHeight(T->Right) == -2) {
            if (X > T->Right->Key)
//                T=SingleLeftRotation(T);
                T = SingleRightRotation(T);
            else
//                T=DoubleLeftRightRotation(T);
                T = DoubleRightLeftRotation(T);

        }
    }
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    return T;
}