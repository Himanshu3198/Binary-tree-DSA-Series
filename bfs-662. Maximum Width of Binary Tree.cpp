/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), righ t(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
//        time complexity O(n)
//        space complexity O(no of nodes at particular level)
    int widthOfBinaryTree(TreeNode* root) {
        
        
           long long int maxWidth=0;
          queue<pair<TreeNode *,long long int>>q;
        
          q.push({root,0});
        
          while(!q.empty()){
              
              
              
                int size=q.size();
                long long int convert=q.front().second;
                  long long int first,last;
              for(long long int i=0;i<size;i++){
                  
                   auto [node,idx]=q.front();
                      q.pop();
                  idx=idx-convert;
                   if(i==0){
                       
                       first=idx;
                   }if(i==size-1){
                       last=idx;
                   }
                  
                  if(node->left){
                      q.push({node->left,2LL*idx+1});
                  }
                  if(node->right){
                      
                      q.push({node->right,2LL*idx+2});
                  }
                  
                  maxWidth=max(maxWidth,last-first+1);
              }
          }
        
        return maxWidth;
        
      
        }
};
