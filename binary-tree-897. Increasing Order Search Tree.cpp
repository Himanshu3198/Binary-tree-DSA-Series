// 897. Increasing Order Search Tree

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
    
      set<int>st;
    
    
       void solve(TreeNode* root){
           
           if(!root){
               return;
           }
           
           solve(root->left);
           st.insert(root->val);
           solve(root->right);
       }
    TreeNode* increasingBST(TreeNode* root) {
        
        
        solve(root);
        
        
        TreeNode *head=NULL ,*newRoot;
        
        for(auto it:st){
            
            if(head==NULL){
                head=new TreeNode(it);
                newRoot=head;
            }
            else{
             newRoot->right=new TreeNode(it);
                newRoot=newRoot->right;
            }
        }
        
        newRoot->right=NULL;
        
        return head;
        
    }
};
