968. Binary Tree Cameras
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

#define nahiChahiye 0
#define chahiye 1
#define milGaya 2
class Solution {
public:
    int camera;
    int solve(TreeNode *root){
        if(!root){
            return nahiChahiye;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        if(left==chahiye || right==chahiye){
            camera++;
            return milGaya;
        }else if(left==milGaya || right==milGaya){
            return nahiChahiye;
        }else{
            return chahiye;
        }
    }
    int minCameraCover(TreeNode* root) {
        camera=0;
        if(solve(root)==chahiye) camera++;
        return camera;
    }
};
