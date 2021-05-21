112. Path Sum
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
    
    
      bool solve(TreeNode*root,int target){
          
          if(!root){
              return false;
          }
          
          if(!root->left and !root->right and root->val==target){
             return true;
              
          }
          target=target-root->val;
          
        return  solve(root->left,target)  or  solve(root->right,target);
          
       
      
          
         
          
          
      }
    bool hasPathSum(TreeNode* root, int target) {
        
        if(!root and target>0){
            return false;
        }
       
        
       return solve(root,target);
    }
};
