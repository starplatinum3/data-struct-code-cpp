//
// Created by Lenovo on 2020/11/19.
//

#include <stdio.h>
#include <stdlib.h>

//typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode {
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;

struct GNode {
//    两个点？
    int Nv;
    int Ne;
    AdjList G;  //邻接表
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool TopSort(LGraph Graph, Vertex TopOrder[]);

int main() {
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();

    if (TopSort(G, TopOrder) == true)
        for (i = 0; i < G->Nv; i++)
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

    return 0;
}

/* Your function will be put here */

//struct GNode{
//    int Nv;
//    int Ne;
//    AdjList G;
//};


LGraph ReadG(){


}


bool TopSort(LGraph Graph, Vertex TopOrder[]) {
//    Vertex 边
//最大 点的个数
    int n = Graph->Nv;
    int *indegree = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)indegree[i] = 0;

    for (int i = 0; i < n; i++) {
        PtrToAdjVNode tmp = Graph->G[i].FirstEdge;
//        第一条边
        while (tmp) {
//        点
            indegree[tmp->AdjV]++;
            tmp = tmp->Next;

        }
    }
    int tail = 0, head = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
//         TopOrder[head++]=i;
            TopOrder[tail++] = i;
//            indegree[i]=-1; 这句可以不写

        }
    }
    while (head < tail) {
        int front = TopOrder[head];
        PtrToAdjVNode tmp = Graph->G[front].FirstEdge;
        while (tmp) {
            indegree[tmp->AdjV]--;
            if (indegree[tmp->AdjV] == 0) {
                TopOrder[tail++] = tmp->AdjV;
//                indegree[tmp->AdjV]=-1;
            }
            tmp = tmp->Next;
        }
        head++;

    }
    return tail == n;
}

//https://blog.csdn.net/wuqi5328/article/details/83550299
bool TopSortRight(LGraph Graph, Vertex TopOrder[]) {
    int n = Graph->Nv;
//    最大的数量
//    indegree
    int *in = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) in[i] = 0;
    for (int i = 0; i < n; i++) {
//        FirstEdge
//临界点node 的指针
//图 i的第一条边
        PtrToAdjVNode temp = Graph->G[i].FirstEdge;
//        从一个点开始，往后找，找到的那些就是有入度的，所以要++
        while (temp) {
//            vertex 点
            in[temp->AdjV]++;
            temp = temp->Next;
        }
    }
    //获得第一个度为0的人
    //int *s=(int*)malloc(sizeof(int)*n);
    int tail = 0, head = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            TopOrder[tail] = i;
            tail++;
            in[i] = -1;
//            来过的不要再来
        }
    }
    int coun = 0;
    while (head != tail) {

        int fron = TopOrder[head];
//        模拟 queue
        PtrToAdjVNode temp = Graph->G[fron].FirstEdge;
        while (temp) {
//            这个点拿掉了，他后面的点的入度就--
            in[temp->AdjV]--;
            if (in[temp->AdjV] == 0) {
//                添新兵，入读为0的
                TopOrder[tail] = temp->AdjV;
                tail++;
                in[temp->AdjV] = -1;
            }
            temp = temp->Next;
        }
        head++;
    }
//    如果不是所有点的数量
    if (tail != n) return false;
    return true;
}