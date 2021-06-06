
// 113. Path Sum II

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
    
    vector<vector<int>>res;
    void solve(TreeNode *root,int target,vector<int>v){
        
        
        
        if(!root) return;
          v.push_back(root->val);
        if(!root->left and !root->right and target==root->val){
          
            res.push_back(v);
            v.clear();
             return;
            
        }
        target=target-root->val;
        solve(root->left,target,v) ;
       solve(root->right,target,v);
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>v;
         solve(root,targetSum,v);
        
        return res;
    }
};
