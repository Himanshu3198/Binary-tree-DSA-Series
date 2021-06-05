// 863. All Nodes Distance K in Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        
        vector<int>res;
        
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>vis;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode *curr=q.front();q.pop();
            
            if(curr->left){
                
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        
        q.push(target);
        vis[target]=true;
        
        while(!q.empty()){
            
            if(k--==0) break;
            
            int qsize=q.size();
            
        for(int i=1;i<=qsize;i++){
            
            TreeNode *curr=q.front();q.pop();
            
            if(curr->left and !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left]=true;
            }
            if(curr->right and !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right]=true;
            }
            
            if(parent[curr] and vis[parent[curr]]==false){
                vis[parent[curr]]=true;
                q.push(parent[curr]);
            }
        }
            
           
        }
        
         while(!q.empty()){
                TreeNode *curr=q.front();q.pop();
                res.push_back(curr->val);
            }
        return res;
    }
};
