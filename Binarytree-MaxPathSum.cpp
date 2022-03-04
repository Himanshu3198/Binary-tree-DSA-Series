    
//  time complexity O(n)
//  space complexity O(1)
int solve(Node*root,int &ans){
        
        if(!root){
            return 0;
        }
        
        int l=max(0,solve(root->left,ans));
        int r=max(0,solve(root->right,ans));
        int curr=root->data+l+r;
        ans=max(ans,curr);
        
         return max(l,r)+root->data;
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int ans=INT_MIN;
        solve(root,ans);
        
         return ans;
    }
