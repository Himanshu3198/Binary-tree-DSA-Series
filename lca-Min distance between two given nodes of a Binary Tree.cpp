 Node *lca(Node *root,int a,int b){
         
         if(!root){
             return NULL;
         }
         
         if(root->data==a or root->data==b){
             return root;
         }
         
         Node *left=lca(root->left,a,b);
         Node *right=lca(root->right,a,b);
         
         
         if(left and right){
             return root;
         }else if(left){
             return left;
         }else{
             return right;
         }
     }
     
     void rootToNode(Node *root,int dist,int target,int &ans){
         
         
         if(!root) return;
         
         if(root->data==target){
             ans=dist;
             return;
         }
         
         rootToNode(root->left,dist+1,target,ans);
         rootToNode(root->right,dist+1,target,ans);
     }
    int findDist(Node* root, int a, int b) {
        // Your code here
        
       Node *common=lca(root,a,b);
        int dist1=0,dist2=0;
        rootToNode(common,0,a,dist1);
        rootToNode(common,0,b,dist2);
        
        return dist1+dist2;
    }
