

/**

513. Find Bottom Left Tree Value
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
    void giveRight(bool *levels,TreeNode* root,int currlevel,vector<int>&vec){
    
        if(root==NULL){
    return;
}
if(levels[currlevel]==false){
    levels[currlevel]=true;
    vec.push_back(root->val);
    
}
        
  giveRight(levels,root->left,currlevel+1,vec);      
giveRight(levels,root->right,currlevel+1,vec);

  
    }
    int findBottomLeftValue(TreeNode* root) {
         
          vector<int>v;
    bool levels[1000]={false};
    giveRight(levels,root,0,v);
        int size=v.size();
        return v[size-1];
 
        
    }
};
