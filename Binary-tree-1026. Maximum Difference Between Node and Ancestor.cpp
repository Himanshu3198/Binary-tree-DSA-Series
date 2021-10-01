// 1026. Maximum Difference Between Node and Ancestor

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
       int dfs( TreeNode * root , int low , int high){ 
         if(root == NULL) return high - low; 
           low = min(low , root->val) ; 
           high = max(high , root->val); 
           return max(dfs(root->left , low , high) , dfs(root->right , low , high)); 
               
       }
    
    int maxAncestorDiff(TreeNode* root) {
        int mx = INT_MIN , mn = INT_MAX; 
        return dfs(root , mn , mx); 
    }
};
