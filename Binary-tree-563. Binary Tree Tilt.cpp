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
      int res;
    
     int solve(TreeNode *root){
         
         if(!root){
             return 0;
         }
         
         int left=solve(root->left);
         int right=solve(root->right);
         
         res+=abs(left-right);
          
        
         return root->val+left+right;
     }
    

    

    int findTilt(TreeNode* root) {
        
        res=0;
         solve(root);
        
        
        return res;
    }
};
