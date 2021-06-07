// 979. Distribute Coins in Binary Tree

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
class Solution {
public:
    int total=0;
    
    
    int helper(TreeNode *root){
        if(!root) return 0;
        
       int left= helper(root->left);
        total+=abs(left);
      int right=  helper(root->right);
        total+=abs(right);
        
        return left+right+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        helper(root);
        
        return total;
    }
};
