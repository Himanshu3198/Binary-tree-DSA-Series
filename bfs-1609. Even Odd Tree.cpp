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
    bool isEvenOddTree(TreeNode* root) {
        
        
        
        queue<TreeNode*>q;
        q.push(root);
        
        int level=-1;
    
        while(!q.empty()){
            
            
            
            level++;
       int even=INT_MAX;
        int odd=INT_MIN;
            
             int size=q.size();
            while(size--){
                
            
            auto node=q.front();
            q.pop();
                
              
                
                if((level%2)==1){
                    
                    if(level>=1 and even!=INT_MAX and even<=node->val){
                        return false;
                    }
                    if((node->val%2)==0){
                        
                        if(node->left){
                            q.push(node->left);
                        }
                        if(node->right){
                            q.push(node->right);
                        }
                    }else{
                        return false;
                    }
                      if(level>=1){
                    
                    if(level%2==1){
                        even=min(even,node->val);
                    }else{
                        odd=max(odd,node->val);
                    }
                }
                    
                    
                    
                }else{
                    
                    if(level>=1 and odd!=INT_MIN and node->val<=odd){
                        return false;
                    }
                    
                    if((node->val%2)==1){
                          if(node->left){
                            q.push(node->left);
                        }
                        if(node->right){
                            q.push(node->right);
                        }
                    }else{
                        return false;
                    }
                    
                      if(level>=1){
                    
                    if(level%2==1){
                        even=min(even,node->val);
                    }else{
                        odd=max(odd,node->val);
                    }
                }
                    
                }
                
            }
            
           
        }
        
        return true;
    }
};
