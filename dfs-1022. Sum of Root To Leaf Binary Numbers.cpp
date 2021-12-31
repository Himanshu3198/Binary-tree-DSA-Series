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
    vector<string>res;
    
      void solve(TreeNode *root,string s){
          
          if(!root) return;
          
          if(root->left==NULL  and root->right==NULL){
              s+=(to_string(root->val));
              res.push_back(s);
          }
          
          solve(root->left,s+to_string(root->val));
         solve(root->right,s+to_string(root->val));

          
      }
    
      
    int sumRootToLeaf(TreeNode* root) {
       
        solve(root,"");
        
         int ans=0;
        for(int i=0;i<res.size();i++){
            
            string curr=res[i];
            cout<<curr<<" ";
               int n=curr.size();
            for(int j=0;j<n;j++){
                
                if(curr[n-j-1]=='1'){
                    ans+=(pow(2,j));
                }
            }
        }
        
        return ans;
        
    }
};
