// 129.sum root to leaf node 

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
    
          int num;
         void solve(TreeNode*root,int digit){
              
           if(!root){
               return ;
           }
              
             digit=digit*10+root->val;
           
           
             if(root->left==NULL and root->right==NULL){
                  
             num+=digit;
             }
           
            solve(root->left,digit);
            solve(root->right,digit);
           
           
           
       
         
            
       }
    int sumNumbers(TreeNode* root) {
        
            num=0;
           solve(root,0);
           return num;
    }
};
