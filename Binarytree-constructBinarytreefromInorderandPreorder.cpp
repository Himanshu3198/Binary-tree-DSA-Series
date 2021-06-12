// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    
    
    TreeNode *solver(vector<int>&pre,vector<int>&in,int start,int end){
 
           
             if(start>end or idx<0) return NULL;
        
        
          int val=pre[idx++];
         
        TreeNode *curr=new TreeNode(val);
        int pos=mp[val];
        
        curr->left=solver(pre,in,start,pos-1);
        curr->right=solver(pre,in,pos+1,end);
        
        return curr;
        
        
        
        
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        
        idx=0;
        
        for(int i=0;i<in.size();i++){
            
            mp[in[i]]=i;
        }
        return solver(pre,in,0,pre.size()-1);
        
    }
};
