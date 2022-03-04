/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
//      time complexiy O(n)+ O(n)
//      space complexity O(n)+O(n)+O(n)
    void solve(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&mp){

       if(!root){
         return;
           }
          if(root->left){
              mp[root->left]=root;
                 solve(root->left,mp);
          }
         if(root->right){
             mp[root->right]=root;
              solve(root->right,mp);
         }
          
   }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>mp;
       
          solve(root,mp);
    
          set<TreeNode *>vis;
        
          queue<pair<TreeNode *,int>>q;
        
          q.push({target,0});
        
          vector<int>res;
        
          while(!q.empty()){
              
              int size=q.size();
              
              while(size--){
                  
                  auto [node,dis]=q.front();
                       q.pop();
                  
                    if(vis.find(node)!=vis.end()){
                        continue;
                    }
                  
                   vis.insert(node);
                  
                  if(dis==k){
                      res.push_back(node->val);
                  }
                  
                  
                  if(node->left ){
                      if(vis.find(node->left)==vis.end())
                         q.push({node->left,dis+1});
                  }
                  
                  if(node->right){
                    if(vis.find(node->right)==vis.end())
                      q.push({node->right,dis+1});
                  }
                  
                  if(mp[node]){
                      
                       if(vis.find(mp[node])==vis.end())
                      q.push({mp[node],dis+1});
                  }
                  
                  
              }
          }
        
        return res;
        
        
        
    }
};
