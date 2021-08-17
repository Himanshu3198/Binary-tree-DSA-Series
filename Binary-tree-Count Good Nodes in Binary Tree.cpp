// Count Good Nodes in Binary Tree
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
        int count=0;
       
      
    
    
     
    
     void dfs(TreeNode *root,int lastnode){
         
          if(!root){
              return;
          }
           if(root->val>=lastnode){
             
               count++;
           }
         
         
         dfs(root->left,max(root->val,lastnode));
         dfs(root->right,max(root->val,lastnode));
         
     }
    int goodNodes(TreeNode* root) {
         if(root and !root->left and !root->right){
           
           return root->val;
       }
         dfs(root,INT_MIN);
        
        return count;
    }
};
