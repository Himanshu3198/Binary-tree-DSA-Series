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
    
    int j=0;
    
    
    TreeNode *solver(vector<int>&pre,vector<int>&in,int start,int end){
        
        if(start>end){
            return NULL;
            
        }
        
        TreeNode *root=new TreeNode(pre[j],NULL,NULL);
        int indexOfinorder=-1;
        
        for(int i=start;i<=end;i++){
            
            if(in[i]==pre[j]){
                indexOfinorder=i;
                break;
            }
        }
        
        j++;
        root->left=solver(pre,in,start,indexOfinorder-1);
        root->right=solver(pre,in,indexOfinorder+1,end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        return solver(pre,in,0,pre.size()-1);
        
    }
};