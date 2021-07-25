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
    
  
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double>res;
        queue<TreeNode*>q;
        q.push(root);
        long long int count;
       long long int ans=0;
        while(!q.empty()){
            
            int size=q.size();
            count=0;
            ans=0;
            while(size--){
                
                count++;
                TreeNode *cur=q.front();
                q.pop();
                
                 ans+=cur->val;
                if(cur->left!=NULL){
                    
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
                
            }
            double ans1=double(ans)/(double)count;
            res.push_back(ans1);
        }
        
        return res;
        
        
    }
};
