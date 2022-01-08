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
          int getMax(vector<int>&nums,int s,int e){
              
              int idx=s;
              int max_ele=nums[idx];
              
              
              for(int i=s;i<=e;i++){
                  
                  if(nums[i]>max_ele){
                      max_ele=nums[i];
                      idx=i;
                  }
              }
              
              return idx;
          }
    
       TreeNode *solve(vector<int>nums,int start,int end){
           
           
           
             if(start>end){
               
                return NULL;
           }
            int idx=getMax(nums,start,end);
           
           
         
           TreeNode *root=new TreeNode(nums[idx]);
           
           
             root->left=solve(nums,start,idx-1);
             root->right=solve(nums,idx+1,end);
          
           return root;
       }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n=nums.size();
    
         
        if(n==0){
            return  NULL;
        }  
             return solve(nums,0,n-1);
             
    
    }
};
