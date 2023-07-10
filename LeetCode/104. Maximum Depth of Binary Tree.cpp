// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Concepts: Tree,Recursion

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)  return 0;

        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
};