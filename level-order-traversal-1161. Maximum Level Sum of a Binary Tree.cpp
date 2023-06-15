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
    int maxLevelSum(TreeNode* root) {
        int ans,maxSum=INT_MIN,level=0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sum=0,size=q.size();
            while(size>0){
                
                auto curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                size--;
            }
            level++;
            if(sum>maxSum){
                maxSum=sum;
                ans=level;
            }
        }
        return ans;
    }
};
