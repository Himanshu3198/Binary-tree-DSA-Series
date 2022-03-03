//  time complexity o(n)
// space complexity O(h)
      void inorder(Node *root,Node* &head,Node* &tail){
          
            if(!root){
            return ;
            }
        
          inorder(root->left,head,tail);
        
         
          
          if(head==0){
              head=tail=root;
          }
          else{
              tail->right=root;
              tail->right->left=tail;
              tail=tail->right;
          }
          
           inorder(root->right,head,tail);
          
      }
      
   
    Node * bToDLL(Node *root)
    {
        // your code 
           Node *head=0,*tail=0;
        if(root==NULL){
            return 0;
        }
        
          inorder(root,head,tail);
          
          return head;
        
      
    }
