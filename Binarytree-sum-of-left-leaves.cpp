
404. Sum of Left Leaves

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
    
    
      void sumLeft(TreeNode *root,int &sum){
          
          if(!root){
              return;
          }
          
          if(root->left){
              
              if(root->left->left==NULL and root->left->right==NULL){
                  sum+=root->left->val;
              }
          }
          
          sumLeft(root->left,sum);
          sumLeft(root->right,sum);
          
          
      }
     int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
       int sum =0;
        sumLeft(root,sum);
        return sum;
    }
 
};
