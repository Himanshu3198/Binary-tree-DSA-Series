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
    int widthOfBinaryTree(TreeNode* root) {
        
        
           int maxWidth=0;
        
          queue<pair<TreeNode *,int>>q;
        
        q.push({root,0});
        
        
        while(!q.empty()){
            
            
            int minNode=q.front().second;
            int size=q.size();
            
            int first,last;
            
            for(int i=0;i<size;i++){
                
                TreeNode *curr=q.front().first;
                 int currIdx=q.front().second-minNode;
                  q.pop();
                
                 if(i==0){
                     first=currIdx;
                 }
                   if(i==size-1){
                     last=currIdx;
                 }
                
                if(curr->left){
                    q.push({curr->left,currIdx*2+1});   
                }
                           
                           
                if(curr->right){
                    q.push({curr->right,currIdx*2+2});
                }
                          
                        
              }
                           
                maxWidth=max(maxWidth,last-first+1);
          }
       
               return maxWidth;
        }
};
