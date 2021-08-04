// 623. Add One Row to Tree

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        queue<TreeNode*>q;
        
        if(depth==1){
            
            auto newnode=new TreeNode(val);
            
            newnode->left=root;
            
            return newnode;
        }
        
        
        q.push(root);
          
        int d=1;
        
        
        
        while(!q.empty()){
            
      
        int size=q.size();
            while(size--){
                
                  auto cur_node=q.front();
                q.pop();
                
                if(d==depth-1){
                    
                    
                    auto left_child=new TreeNode(val);
                     auto right_child=new TreeNode(val);
                    
                    left_child->left=cur_node->left;
                    
                    right_child->right=cur_node->right;
                    
                    cur_node->left=left_child;
                    cur_node->right=right_child;
                
                }
                else{
                    
                    if(cur_node->left){
                        
                        q.push(cur_node->left);
                    }
                      if(cur_node->right){
                        
                        q.push(cur_node->right);
                    }
                }
            }
               
                
                d++;
                
           
    
        
            
        }
        
        
        return root;
    }
};
