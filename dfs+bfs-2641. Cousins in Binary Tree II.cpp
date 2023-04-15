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
     TreeNode * solve(TreeNode *root,vector<int>&v,int idx,int sum){
         
         if(!root || idx==v.size()){
             return NULL;
         }
         int newS=0;
        TreeNode * res=new TreeNode(v[idx]-sum);
         if(root->left) newS+=root->left->val;
         if(root->right)newS+=root->right->val;
          
          res->left=solve(root->left,v,idx+1,newS);
          res->right=solve(root->right,v,idx+1,newS);
          return res;
          
     }
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        vector<int>v;
       
        queue<TreeNode*>q;
        q.push(root);
   
        while(!q.empty()){
            
            int size=q.size(),ans=0;
            
            for(int i=0;i<size;i++){
                TreeNode * node=q.front();
                ans+=node->val;
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            v.push_back(ans);
        }
        return solve(root,v,0,root->val);
      
    }
};
