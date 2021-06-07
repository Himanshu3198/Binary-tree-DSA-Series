
// 1372. Longest ZigZag Path in a Binary Tree

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
    
      void solve(TreeNode *root,int l,int r,int &ans){
          
          if(!root) return ;
          
          ans=max(ans,l);
          ans=max(ans,r);
          
          solve(root->left,0,l+1,ans);
          solve(root->right,r+1,0,ans);
      }
    int longestZigZag(TreeNode* root) {
       int l=0,r=0,ans=0;
        
        solve(root,l,r,ans);
        return ans;
    }
};
