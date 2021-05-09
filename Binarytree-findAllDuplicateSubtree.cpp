652. Find Duplicate Subtrees

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

      string solve(TreeNode*root,vector<TreeNode*>&res,unordered_map<string,int>&mp){
          
          if(!root){
              return "";
          }
          
          string s=to_string(root->val)+","+solve(root->left,res,mp)+","+solve(root->right,res,mp);
          
          mp[s]++;
          
          if(mp[s]==2){
              res.push_back(root);
          }
          return s;
      }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*>res;
          unordered_map<string,int>mp;
        
          solve(root,res,mp);
          return res;
    }
};
