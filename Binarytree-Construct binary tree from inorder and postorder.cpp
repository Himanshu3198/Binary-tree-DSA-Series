106. Construct Binary Tree from Inorder and Postorder Traversal


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
     int idx;
   
      unordered_map<int,int>mp;
    
      TreeNode *helper(vector<int>& inorder, vector<int>& postorder,int start,int end){
          
                
    if(start>end ){
              return NULL;
          }
          int val=postorder[idx];
             
            idx--;
        
        
          
           TreeNode *curr=new TreeNode(val);
          
           if(start==end){
              return curr;
          }
          
          // int pos=search(inorder,start,end,val);
          
          int pos=mp[val];
       
           curr->right=helper(inorder,postorder,pos+1,end);
          curr->left=helper(inorder,postorder,start,pos-1);
          
          
          return curr;
          
          
      }
      
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
           
         idx =postorder.size()-1;
           int start=0;
           int end=inorder.size()-1;
        
           if(start==end){
           
             TreeNode *newNode= new TreeNode(postorder[start]);
              return newNode;
          }
        
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return helper(inorder,postorder,start,end);
        
    }
        
        
};
