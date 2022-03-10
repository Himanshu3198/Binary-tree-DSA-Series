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
    
      bool solve(TreeNode *root,TreeNode *subTree){
          
            if(!root or !subTree){
               return root==NULL and subTree==NULL;
            }
            else if(root->val==subTree->val){
                return solve(root->left,subTree->left) and solve(root->right,subTree->right);
            }
                return false;
            
              
          
          
      }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
            if(!root) return false;
        
           else if(solve(root,subRoot)){
               return true;
           }else{
                      return (isSubtree(root->left,subRoot)  || isSubtree(root->right,subRoot));
   
           }
    }
};
