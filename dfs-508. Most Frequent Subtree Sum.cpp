508. Most Frequent Subtree Sum
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
       vector<int>res;
       unordered_map<int,int>mp;
    int maxCount=0;
    
      int solve(TreeNode *root){
          
          if(!root) return 0;
          
            
             int left=solve(root->left);
             int right=solve(root->right);
          
            int num=root->val+left+right;
             maxCount=max(maxCount,++mp[num]);
             return num;
      }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        solve(root);
        
         for(auto it:mp){
             
             if(it.second==maxCount){
                 res.push_back(it.first);
             }
         }
        return res;
    }
};
