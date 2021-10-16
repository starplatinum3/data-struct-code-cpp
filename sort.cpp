//
// Created by Lenovo on 2020/6/12.
//
#include<stdio.h>
#include <algorithm>
#include <random>
/* 快速排序 */
typedef int ElementType;
void Qsort(ElementType A[], int Left, int Right); /* 核心递归函数 */
void QuickSort(ElementType A[], int N); /* 统一接口 */

void quickSortTest() {
    printf("quick Sort Test\n");
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 111);
    // std::cout << dist6(rng) << std::endl;

//    std::uniform_real_distribution<double> distribution(-1, 1);
//    std::cout << distribution(rng) << std::endl;
    int n = 22;
    int a[22];
    // srand(time(0));
    for (int i = 0; i < n; i++)a[i] = dist6(rng);
    printf("before\n");
    for (auto x:a) {
        printf("%d ", x);
    }
    printf("\n");
    QuickSort(a, n);
    printf("after\n");
    for (auto x:a) {
        printf("%d ", x);
    }
    printf("\n");
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

}


void bubbleSortTest() {
    int a[11];
    for (int i = 0; i < 11; i++)a[i] = 11 - i;
    bubbleSort(a, 11);
    for (auto x:a) {
        printf("%d ", x);
    }
}


void Swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void InsertionSort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int minn = i;
        for (int j = i + 1; j < n; j++) {
            if (A[minn] > A[j])minn = j;
        }
        if (minn != i)
            std::swap(A[minn], A[i]);
    }
}

ElementType Median3(ElementType A[], int Left, int Right) {
    int Center = (Left + Right) / 2;
    if (A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    /* 此时A[Left] <= A[Center] <= A[Right] */
    Swap(&A[Center], &A[Right - 1]); /* 将基准Pivot藏到右边*/
    /* 只需要考虑A[Left+1] … A[Right-2] */
    return A[Right - 1];  /* 返回基准Pivot */
}

void Qsort(ElementType A[], int Left, int Right) { /* 核心递归函数 */
    int Pivot, Cutoff, Low, High;
    Cutoff = 22;
    if (Cutoff <= Right - Left) { /* 如果序列元素充分多，进入快排 */
        Pivot = Median3(A, Left, Right); /* 选基准 */
        Low = Left;
        High = Right - 1;
        while (true) { /*将序列中比基准小的移到基准左边，大的移到右边*/
            while (A[++Low] < Pivot);
            while (A[--High] > Pivot);
            if (Low < High) Swap(&A[Low], &A[High]);
            else break;
        }
        Swap(&A[Low], &A[Right - 1]);   /* 将基准换到正确的位置 */
        Qsort(A, Left, Low - 1);    /* 递归解决左边 */
        Qsort(A, Low + 1, Right);   /* 递归解决右边 */
    } else InsertionSort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 */
}

void QuickSort(ElementType A[], int N) { /* 统一接口 */
    Qsort(A, 0, N - 1);
}

typedef int ElementType ;
/* 归并排序 - 递归实现 */

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
    int LeftEnd, NumElements, Tmp;
    int i;

    LeftEnd = R - 1; /* 左边终点位置 */
    Tmp = L;         /* 有序序列的起始位置 */
    NumElements = RightEnd - L + 1;

    while( L <= LeftEnd && R <= RightEnd ) {
        if ( A[L] <= A[R] )
            TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
        else
            TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
    }

    while( L <= LeftEnd )
        TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
    while( R <= RightEnd )
        TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

    for( i = 0; i < NumElements; i++, RightEnd -- )
        A[RightEnd] = TmpA[RightEnd];
    /* 将有序的TmpA[]复制回A[] */
}


void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{ /* 核心递归排序函数 */
    int Center;

    if ( L < RightEnd ) {
        Center = (L+RightEnd) / 2;
        Msort( A, TmpA, L, Center );              /* 递归解决左边 */
        Msort( A, TmpA, Center+1, RightEnd );     /* 递归解决右边 */
        Merge( A, TmpA, L, Center+1, RightEnd );  /* 合并两段有序序列 */
    }
}

void MergeSort( ElementType A[], int N )
{ /* 归并排序 */
    ElementType *TmpA;
    TmpA = (ElementType *)malloc(N*sizeof(ElementType));

    if ( TmpA != NULL ) {
        Msort( A, TmpA, 0, N-1 );
        free( TmpA );
    }
    else printf( "空间不足" );
}

const int N=1e5+10;
int a[N];
int testMergeSort() {
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    MergeSort(a,n);
    int fir=1;
    for(i=0;i<n;i++){
        if(fir){
            printf("%d",a[i]);
            fir=0;
        } else{
            printf(" %d",a[i]);
        }

    }
    printf("\n");
    return 0;
}

//基数排序
void testRadixSort(){

}

