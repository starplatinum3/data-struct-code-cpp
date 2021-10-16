//Designed By Dark http://blog.csdn.net/xzongyuan
#include "build_tree.h"

int insert_tree(Tree pTree,int pValue)
{

   //found NULL sub tree, then add to his father->left
   if(!pTree)
   {
      return 0;
   }
   TNode *tNode = init_TNode(pValue);
   if(tNode==NULL)
   {
       printf("create TNode error!\n");
       return 0;
   }
	   

   if(pValue < pTree->value) 
        if(insert_tree(pTree->left,pValue)==0)
        {
	   //no left child any more,set a new left child to pTree
	   pTree->left = tNode;
   	   printf("insert :%d\n",pValue);
	}
   if(pValue > pTree->value)
        if(insert_tree(pTree->right,pValue)==0)
        {
           pTree->right = tNode;
	   printf("insert :%d\n",pValue);
        }
}

Tree creatTree(int num)
{
    srand(time(NULL));
    Tree root = init_TNode(rand()%100);
    printf("root is %d\n",root->value);
    int i ;
    for(i=1;i<num;i++)
    {
        insert_tree(root,rand()%100); 
    }
    printf("creat tree succuess!Tree heigh is:%d\n",get_tree_height(root));
    return root ;
}

int get_tree_height(Tree pRoot)
{

  if(!pRoot)
  {
    return 0; 
  }

  int lh=0,rh=0;
  lh = get_tree_height(pRoot->left);
  rh = get_tree_height(pRoot->right);
  return (lh<rh)?(rh+1):(lh+1);
}
