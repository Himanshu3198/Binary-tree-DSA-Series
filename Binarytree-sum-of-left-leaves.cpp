
404. Sum of Left Leaves

   int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
       int sum =0;
        sumLeft(root,sum);
        return sum;
    }
    void sumLeft(TreeNode* root, int& sum) {
        if(!root)
            return;
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            sum+=root->left->val;
        }
        sumLeft(root->right,sum);
        sumLeft(root->left,sum);
    }
