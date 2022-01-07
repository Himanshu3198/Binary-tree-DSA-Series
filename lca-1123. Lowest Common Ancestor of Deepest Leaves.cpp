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
    
         int solve(TreeNode *root){
          
          if(!root) return 0;
          
          int left=solve(root->left);
          int right=solve(root->right);
          
          return max(left,right)+1;
      }
    
      TreeNode*helper(TreeNode*root){
          
          int left=solve(root->left);
          int right=solve(root->right);
          
          if(left==right) return root;
          
          else{
              
              if(left>right) return helper(root->left);
              
              return helper(root->right);
          }
        
      }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root);
    }
};
