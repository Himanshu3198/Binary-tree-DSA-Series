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
    int res=0;
       
    
          int depth(TreeNode*root){
              
              if(!root) return 0;
              
               return 1+max(depth(root->left),depth(root->right));
          }
        void solve(TreeNode*root,int d){
            if(!root) return;
            
            if(!d){
                
                res+=root->val;
            }
            
            solve(root->left,d-1);
            solve(root->right,d-1);
        }
    int deepestLeavesSum(TreeNode* root) {
        int d=depth(root);
        solve(root,d-1);
        return res;
    }
};
