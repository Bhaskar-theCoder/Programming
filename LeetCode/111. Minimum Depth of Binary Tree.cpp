// Problem Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Concepts: Tree,DFS,BFS

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)  return 0;
        if(root->left==NULL&&root->right==NULL)  return 1;
        int a=INT_MAX,b=INT_MAX;
        if(root->left!=NULL)    a=1+minDepth(root->left);
        if(root->right!=NULL)   b=1+minDepth(root->right);

        return min(a,b);
    }
};