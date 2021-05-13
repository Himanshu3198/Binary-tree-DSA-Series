
// Reverse Level Order Traversal 
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    
    queue<Node*>q;
    q.push(root);
    
    vector<int>res;
    
    while(!q.empty()){
        
        Node *temp=q.front();
        q.pop();
        res.push_back(temp->data);
        
     
         if(temp->right!=NULL){
            
            q.push(temp->right);
        }
        
         if(temp->left!=NULL){
            
            q.push(temp->left);
        }
    }
    
    reverse(res.begin(),res.end());
    return res;
}
