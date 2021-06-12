// 1145. Binary Tree Coloring Game

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
    
 
    TreeNode*findNode(TreeNode *root,int x){
        
        if(!root) return NULL;
            
            
            if(root->val==x){
                return root;
            }
        
        TreeNode *l= findNode(root->left,x);
        TreeNode *r= findNode(root->right,x);
        
       if(l!=NULL){
           return l;
       }
        return r;
        
    }
    void countNodes(TreeNode*root,int &count){
        if(root!=NULL){
            
            
            count++;
            countNodes(root->left,count);
            countNodes(root->right,count);
        }
    }
    
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        
        int count1=0,count2=0,parent=0;
        
        TreeNode* temp=findNode(root,x);
        
        countNodes(temp->left,count1);
        countNodes(temp->right,count2);
        
        int blueWins=max(count1,count2);
        
        
        if(root->val!=temp->val){
            parent=n-(count1+count2+1);
        }
        
        blueWins=max(blueWins,parent);
        
        
        return (blueWins>n-blueWins);
        
    
        
    }
};
