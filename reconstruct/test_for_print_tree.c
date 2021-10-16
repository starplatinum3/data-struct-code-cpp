#include<stdio.h>
#include<stdlib.h>
#define NUM 7
#include "queue.h"
#include "build_tree.h"
#include "print_tree.h"

int main(int argc,char **argv)
{
  Queue *queue=init_queue();
  int i;

  ifEmpty(queue);
  printf("insert node to queue\n");

  int num = NUM; //default
  if(argc == 2)
  {
    num = atoi(argv[1]); 
  }

  Tree root = creatTree(num);
  if(!root)
  {
    printf("create Tree failed!\n");
    return 0;
  }

  print_tree(root,queue);
  return 0;
}
