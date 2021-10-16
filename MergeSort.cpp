//
// Created by Lenovo on 2020/12/10.
//

#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef struct {
    KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/
    int Length;
} SqList;

void CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/
void MergeSort(SqList L, int low, int high);

void Merge(SqList L, int low, int m, int high);

int main() {
    SqList L;
    int i;
    CreatSqList(&L);
    MergeSort(L, 1, L.Length);
    for (i = 1; i <= L.Length; i++) {
        printf("%d ", L.elem[i]);
    }
    return 0;
}

void MergeSort(SqList L, int low, int high) {
    /*用分治法进行二路归并排序*/
    int mid;
    if (low < high)  /*区间长度大于1*/
    {
        mid = (low + high) / 2;               /*分解*/
        MergeSort(L, low, mid);           /*递归地对low到mid序列排序 */
        MergeSort(L, mid + 1, high);        /*递归地对mid+1到high序列排序 */
        Merge(L, low, mid, high);          /*归并*/
    }
}

/*你的代码将被嵌在这里 */

void Merge(SqList L, int low, int m, int high) {
//    mid  m
    int LeftEnd, NumElements, Tmp;
    int i;
    LeftEnd = high - 1; /* 左边终点位置 */
    Tmp = low;         /* 有序序列的起始位置 */
    NumElements = high - low + 1;
//    printf("NumElements :%d\n",NumElements);
//    https://bbs.csdn.net/topics/390501095
//    SqList *TmpA = (SqList *) malloc(high * sizeof(SqList));
    int *arr=(int*)malloc(sizeof(int)*1111);
//    if (TmpA == NULL)
//        printf("TmpA==NULL\n");
    while (low <= LeftEnd && m <= high) {
        if (L.elem[low] <= L.elem[m])
            arr[Tmp++] = L.elem[low++]; /* 将左边元素复制到TmpA */
        else{
//            TmpA->elem[Tmp++] = L.elem[m++];
            /* 将右边元素复制到TmpA */
            arr[Tmp++]= L.elem[m++];
        }
    }

    while (low <= LeftEnd)
        arr[Tmp++] = L.elem[low++]; /* 直接复制左边剩下的 */
    while (m <= high)
        arr[Tmp++] = L.elem[m++]; /* 直接复制右边剩下的 */

    for (i = 0; i < NumElements; i++, high--)
        L.elem[high] = arr[high];
    /* 将有序的TmpA[]复制回A[] */
    free(arr);
}
