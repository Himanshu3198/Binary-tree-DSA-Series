// 987. Vertical Order Traversal of a Binary Tree


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        TreeNode *curr;
        int h=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,h});
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        
        //BFS
        while(!q.empty())
        {
            int size = q.size();            
               vector<pair<int,int>>v;
            
            while(size--)
            {
                  auto temp=q.front();
                q.pop();
                
                TreeNode *node=temp.first;
                 h=temp.second;
                 v.push_back({node->val,h});
                
                if(node->left)
                    q.push({node->left,h-1});
                if(node->right)
                    q.push({node->right,h+1});
            }
              std::sort(v.begin(),v.end());
            
            for(auto x:v){
                
                mp[x.second].push_back(x.first);
            }
        }
        //Now pass all values from mymap to ans array
        for(auto it: mp)
            ans.push_back(it.second);
        
        return ans;
    }
};
