/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
	public:
		bool hasPathSum(TreeNode* root, int targetSum) {
			return dfs(root,targetSum,0);
		}
		bool dfs(TreeNode* node,int targetSum,int nowSum) {
			if(node==nullptr) {
				if(nowSum==targetSum) {
					return true;
				}
				return false;
			}
			if(node->left!=nullptr) {
				return  dfs(node->left,targetSum,nowSum+node->val);
			}
			if(node->right!=nullptr) {
				return  dfs(node->right,targetSum,nowSum+node->val);
			}
			if(nowSum==targetSum) {
				return true;
			}
			return false;
		}
};
