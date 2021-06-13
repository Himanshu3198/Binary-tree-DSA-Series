// 515. Find Largest Value in Each Tree Row

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
    vector<int> largestValues(TreeNode* root) {
                vector<int >res;
        
        if(!root){
            return res;
        }
      
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
              int maxVal=INT_MIN;
            int size=q.size();
            while(size--){
                
                auto curr=q.front();
                q.pop();
                maxVal=max(curr->val,maxVal);
                
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
             
            }
            
            res.push_back(maxVal);
        }
        
        return res;
        
       
    }
};
