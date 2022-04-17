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
    TreeNode *prev,*curr;
      void solve(TreeNode *root){
        if(!root) return;
        solve(root->left);
        if(prev){
            prev->right=root;
        }else{
            curr=root;
        }
        root->left=NULL;  
        prev=root;
        solve(root->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        prev=NULL,curr=NULL;
        solve(root);
        return curr;
        
        
    }
};
