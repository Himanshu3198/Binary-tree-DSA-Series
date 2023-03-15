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
    bool isCompleteTree(TreeNode* root) {
        
        
        
         queue<TreeNode*>q;
         bool leftChildNull=false;
         q.push(root);
         while(!q.empty()){
             int size=q.size();
             while(size--){
           
              TreeNode *curr=q.front();
              q.pop();
              if(curr==NULL)  leftChildNull=true;
              else{
                  if(leftChildNull) return false;
                  q.push(curr->left);
                  q.push(curr->right);
              }   
             }
         }
        return true;
    }
};
