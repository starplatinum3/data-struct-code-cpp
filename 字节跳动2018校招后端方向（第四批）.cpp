//���ӣ�https://www.nowcoder.com/questionTerminal/179ae546ed4c425397f744461f621094
//��Դ��ţ����

#include<bits/stdc++.h>
using namespace std;
  #include <stack>


 struct TreeNode {

       int val;  

      TreeNode *left, *right;  

 };
TreeNode* Convert(TreeNode* root) {
    if(root == NULL)    return NULL;
    TreeNode* listHead = NULL;
    TreeNode* listLastHead = NULL;
    stack<TreeNode*> s;
    
    while(root || !s.empty()) {
        while(root) {
            s.push(root);
            root = root->left;
        }
//        �ҵ�������ߵ� 
        root = s.top();
        s.pop();
//        һ��ʼ��û��head�� 
        if(listHead == NULL) {
            listHead = root;
        } else {
//        	�ϴε�ͷ 
            listHead->left = listLastHead;
//            ���ұ��� 
            listLastHead->right = listHead;
        }
        listLastHead = root;
        root = root->right;
    }
}

int main(){
	TreeNode* root=new TreeNode();
	root->val=10;
	root->left=new TreeNode();
	Convert();
} 
