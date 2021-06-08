// 1339. Maximum Product of Splitted Binary Tree

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

 const int mod=1e9+7;
 #define ll long long int
class Solution {
public:
    ll total=0,ans=0;
    
    
    int solve1(TreeNode *root){
        
        if(!root) return 0;
        
        return solve1(root->left)+solve1(root->right)+root->val;
    }
    int solve2(TreeNode*root){
        
        if(!root) return 0;
        
        ll l=solve2(root->left);
        ll r=solve2(root->right);
        
        ll up=total-l-r-root->val;
        
        ll op1=(l*((ll)root->val+r+up));
        
        ll op2=(r*((ll)root->val+l+up));
                
        ans=max(ans,max(op1,op2));
                
        ll op3=(up*((ll)root->val+l+r));
                ans=max(ans,op3);
                
                return l+r+root->val;
                
    }
     
    int maxProduct(TreeNode* root) {
      
         total=solve1(root);
        solve2(root);
        return ans%mod;
    }
};
