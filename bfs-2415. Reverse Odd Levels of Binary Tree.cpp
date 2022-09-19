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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            
            int size=q.size();
            queue<TreeNode*>serial;
            stack<int>st;
            while(size--){
                
                auto [node,level]=q.front();
                q.pop();
                if(level&1){
                    serial.push(node);
                    st.push(node->val);
                }
                if(node->left) q.push({node->left,level+1});
                if(node->right) q.push({node->right,level+1});
            }
            while(!serial.empty() && !st.empty()){
                
                 auto curr=serial.front();
                 serial.pop();
                curr->val=st.top();
                st.pop();
            }
        }
        return root;
    }
};
