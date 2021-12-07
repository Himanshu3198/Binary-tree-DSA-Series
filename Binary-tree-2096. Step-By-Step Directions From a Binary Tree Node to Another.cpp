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
    
    
       TreeNode* lca(TreeNode *root, int startVal,int destVal){
           
           if(!root) return NULL;
           
           
           if(root->val==startVal or root->val==destVal){
               return root;
           }
           
          TreeNode *l=lca(root->left,startVal,destVal);
           TreeNode *r=lca(root->right,startVal,destVal);
           
           if(l and r){
               return root;
           }
           if(l){
               return l;
           }
           return r;
           
       }
    
    bool isValid(TreeNode *root,int target,string &path){
        
         if(root->val==target){
             return true;
         }
        
        if(root->left){
            
            if(isValid(root->left,target,path)){
                path+='L';
                return true;
            }
        }
        if(root->right){
            
            if(isValid(root->right,target,path)){
                path+='R';
                return true;
            }
        }
        
        return false;
    }
    
       
    string getDirections(TreeNode* root, int startVal, int destVal) {
        
        
        
         TreeNode* commonParent=lca(root,startVal,destVal);
        
            string path1="";
            string path2="";
        
            isValid(commonParent,startVal,path1);
           isValid(commonParent,destVal,path2);
        
          for(int i=0;i<path1.size();i++){
              
              path1[i]='U';
          }
        
         reverse(path2.begin(),path2.end());
        
         string res=path1+path2;
        
        return res;
        
    }
};
