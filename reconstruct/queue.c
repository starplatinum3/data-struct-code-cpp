//Designed By Dark http://blog.csdn.net/xzongyuan
#include "queue.h"


Queue* init_queue()
{
   Queue *queue=(Queue*)malloc(sizeof(Queue));
   queue->head = queue->tail = NULL;
   return queue;
}

int enQueue(Queue *pQueue,TNode *pTNode,int pDepth)
{

      QNode *pQNode = (QNode *)malloc(sizeof(QNode));
      pQNode->depth = pDepth;
      pQNode->blank = 0; //default config 
      if(pTNode==NULL)
      {
         //change default setting; 1 means it's blank QNode
         pQNode->blank =1;
      }

      pQNode->t_node= pTNode;
      if(pQueue->head == NULL)
      {//when it's empty
           pQueue->head = pQNode; 
	   pQueue->tail = pQNode;     
      }    
      else
      {
           pQueue->tail->next = pQNode;
	   pQueue->tail = pQNode;
      }
}

QNode* deQueue(Queue *pQueue)
{
	if(pQueue->head == NULL)
	{
	   return NULL;
	}

	QNode *deNode= pQueue->head;
	pQueue->head = pQueue->head->next;  
        return deNode;
}


//0:empty
int ifEmpty(Queue *pQueue)
{
   if(pQueue->head == NULL)
   {
     //printf("empty tree\n");
     return 0;
   }
   
   //printf("queue is not empty\n");
   return 1;
}


