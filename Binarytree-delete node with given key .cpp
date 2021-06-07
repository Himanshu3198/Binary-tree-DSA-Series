// 1325. Delete Leaves With a Given Value

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
   
    
      TreeNode* solve(TreeNode *root,int target){
           
           
           if(!root) return NULL;
           root->left=solve(root->left,target);
          root->right=solve(root->right,target);
          
          if(root->val==target and !root->left and  !root->right){
              
              return NULL;
          }
             return root;
       }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        
           solve(root,target);
        
        if(!root->left and !root->right and root->val==target){
            return NULL;
        }
        return root;
    }
};
