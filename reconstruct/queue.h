#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

typedef struct _q_node
{
  TNode *t_node;
  int depth;
  int blank;  //0: means correspoinding tree node is not NULL(default)
  struct _q_node *next;
}QNode;

typedef struct _Queue
{
   QNode *head;
   QNode *tail;
}Queue;

Queue* init_queue();

int enQueue(Queue *pQueue,TNode *pTNode,int pDepth);

QNode* deQueue(Queue *pQueue);

int ifEmpty(Queue *pQueue);

#endif
