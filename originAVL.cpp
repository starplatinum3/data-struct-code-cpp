//
// Created by Lenovo on 2020/10/25.
//

//这个是博主 左右搞反了


int Max(int a, int b){
    return a>b?a:b;
}

int GetHeight(AVLTree A){
    if(A==NULL)
        return 0;
    return A->Height;
}

AVLTree SingleLeftRotation(AVLTree A){
    AVLTree B=A->Right;
    A->Right=B->Left;
    B->Left=A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Right), A->Height) + 1;
    return B;
}

AVLTree SingleRightRotation(AVLTree A){
    AVLTree B=A->Left;
    A->Left=B->Right;
    B->Right=A;
    A->Height=Max(GetHeight(A->Left), GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Left),A->Height)+1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A){
    A->Right = SingleRightRotation(A->Right);
    return SingleLeftRotation(A);
}


AVLTree DoubleRightLeftRotation(AVLTree A){
    A->Left = SingleLeftRotation(A->Left);
    return SingleRightRotation(A);
}

//https://blog.csdn.net/qq_40215528/article/details/84939945
AVLTree Insert(AVLTree T,int X){
    if(!T){
        T=(AVLTree)malloc(sizeof(struct AVLNode));
        T->Key=X;
        T->Height=1;
        T->Left=T->Right=NULL;
    }

    else if(X<T->Key){ //插入左子树
        T->Left=Insert(T->Left, X);
        if(GetHeight(T->Left)-GetHeight(T->Right)==2){
            if (X<T->Left->Key) {
                T=SingleRightRotation(T);
            }
            else
                T=DoubleRightLeftRotation(T);
        }
    }

    else if(X>T->Key){
        T->Right=Insert(T->Right, X);
        if(GetHeight(T->Left)-GetHeight(T->Right)==-2){
            if (X>T->Right->Key)
                T=SingleLeftRotation(T);
            else
                T=DoubleLeftRightRotation(T);

        }
    }
    T->Height=Max(GetHeight(T->Left), GetHeight(T->Right))+1;
    return T;
}