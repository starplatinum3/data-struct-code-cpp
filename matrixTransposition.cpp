//
// Created by Lenovo on 2020/10/16.
//

#include <stdio.h>

#include <stdlib.h>
#include "mylib.h"
#include <iostream>

#define MAX_TRIPLETABLE_SIZE 100

struct node {

    int i, j, v;

};

//https://blog.csdn.net/qq_34453300/article/details/87469822?spm=1000.2123.3001.4430
struct tripletable {

    struct node data[MAX_TRIPLETABLE_SIZE];

    int m, n, nodeCount;

};


struct tripletable *create() {
    int i;

    struct tripletable *head = (struct tripletable *) malloc(sizeof(struct tripletable));

    printf("输入第1行为矩阵行数m、列数n及非零元素个数t\n");
    scanf("%d%d%d", &(head->m), &(head->n), &(head->nodeCount));

//  一共t个数据

    printf("按行优先顺序依次输入t行，每行3个数，分别表示非零元素的行标、列标和值\n");
    for (i = 0; i < head->nodeCount; i++)

        scanf("%d%d%d", &(head->data[i].i), &(head->data[i].j), &(head->data[i].v));

    return head;

}


void print(struct tripletable *head) {

    int i;

    for (i = 0; i < head->nodeCount; i++)

        printf("%d %d %d\n", (head->data[i].i), (head->data[i].j), (head->data[i].v));

}


struct tripletable *trans(struct tripletable *oldTripletable);

int matrixTransposition() {

    struct tripletable *head, *t2;

    head = create();
    std::cout << "head: " << head << "\n";
//    t2 = trans(head);
    t2=  fastTrans(head) ;
    std::cout << "t2: " << t2 << "\n";

    print(t2);

    return 0;

}


/* 请在这里填写答案 */

//https://blog.csdn.net/goodman_lqifei/article/details/77724322
struct tripletable *trans(struct tripletable *oldTripletable) {
    auto *outTable = new tripletable();
    outTable->m = oldTripletable->n;

    outTable->n = oldTripletable->m;
    outTable->nodeCount = oldTripletable->nodeCount;
    if (oldTripletable->nodeCount == 0)
        return nullptr;
    int q = 0;
//oldTripletable 的行数 就是new的列数
//对于new 的每一列，我们去看old的每一个的列，如果和new的col相等，
// 那么说明old的那个格子是要转置过来的
    for (int col = 0; col < oldTripletable->n; col++)
        for (int p = 0; p < oldTripletable->nodeCount; p++) {
            if (oldTripletable->data[p].j == col) {
                outTable->data[q].i = oldTripletable->data[p].j;
                outTable->data[q].j = oldTripletable->data[p].i;
                outTable->data[q].v = oldTripletable->data[p].v;
                ++q;
            }
        }

    return outTable;
}
/**
 *稀疏矩阵快速转置
 * @参考 https://blog.csdn.net/goodman_lqifei/article/details/77724322
 * @param oldTripletable
 * @return
 */
struct tripletable *fastTrans(struct tripletable *oldTripletable) {

    tripletable *outTable = new tripletable();

    outTable->m = oldTripletable->n;

    outTable->n = oldTripletable->m;


    outTable->nodeCount = oldTripletable->nodeCount;

    int num[oldTripletable->n + 1], cpot[oldTripletable->n + 1];

    int col, t, p, q;

//     nodeCount ,number of not 0

//     for(i=0;i<head->nodeCount;i++) 0 is the head

    if (oldTripletable->nodeCount) {

        for (col = 0; col < oldTripletable->n; col++)

            num[col] = 0;

        for (t = 0; t < oldTripletable->nodeCount; t++)
            ++num[oldTripletable->data[t].j ];
//            ++num[oldTripletable->data[t].j - 1];

//         s data 里面 第t个元素的 列号

//         这一列如果有元素的话 就++

//         就是算出这列有多少元素

        cpot[0] = 0;

        //第0行元素的起始下标为0

        for (col = 1; col < oldTripletable->nodeCount; col++) {

            cpot[col] = cpot[col - 1] + num[col - 1];

        }

        //如果我第二列有3个数字，那么我第三列的下标就是

//         第二列的数字加上之前所有的下标

//         第二列开始是2，也就是第一列的cpot ：0+

//         第一列的个数：2=2

//         就是得到每一列的开始

        for (p = 0; p < oldTripletable->nodeCount; p++) {

//             所有的元素

//             元素的列

            col = oldTripletable->data[p].j;

//            q = cpot[col] - 1;
            q = cpot[col] ;

//             我原来这列的

            outTable->data[q].j = oldTripletable->data[p].i;

            outTable->data[q].i = oldTripletable->data[p].j;

            outTable->data[q].v = oldTripletable->data[p].v;

            cpot[col]++;

        }


    }
    return outTable;

}