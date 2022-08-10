//链接：https://www.nowcoder.com/questionTerminal/179ae546ed4c425397f744461f621094
//来源：牛客网

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
//        找到了最左边的 
        root = s.top();
        s.pop();
//        一开始是没有head的 
        if(listHead == NULL) {
            listHead = root;
        } else {
//        	上次的头 
            listHead->left = listLastHead;
//            往右边走 
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
