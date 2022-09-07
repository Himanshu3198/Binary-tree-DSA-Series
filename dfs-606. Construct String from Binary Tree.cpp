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
       
       string solve(TreeNode * root){
        if(!root){
            return "";
        }
        string ans=to_string(root->val);
        if(root->left){
            ans+="("+solve(root->left)+")";
        }
        if(root->right){
            if(!root->left) ans+="()";
            ans+="("+solve(root->right)+")";
        }
        return ans;
    }
    string tree2str(TreeNode* root) {
      
       return solve(root);
     
    }
};
