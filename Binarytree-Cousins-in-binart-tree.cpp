// 993. Cousins in Binary Tree
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
    
      TreeNode *parent_x,*parent_y;
    
     int depth_x, depth_y;
    
        void solve(TreeNode *root,TreeNode *parent,int x,int y,int d){
            
            if(!root){
                return ;
            }
            
            if(root->val==x){
                parent_x=parent;
                depth_x=d;
            }
            
            if(root->val==y){
                parent_y=parent;
                depth_y=d;
            }
            
            solve(root->left,root,x,y,d+1);
            solve(root->right,root,x,y,d+1);
        }
    bool isCousins(TreeNode* root, int x, int y) {
         int d=0;
        if (root->val == x || root->val == y)
            return false;
        solve(root->left,root,x,y,d);
        solve(root->right,root,x,y,d);
        
        return (depth_x==depth_y) &&(parent_x!=parent_y);
        
    }
   
   
};    
