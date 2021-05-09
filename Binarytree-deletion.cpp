

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node*right;
};

struct Node *newNode(int data)
{
    struct Node *newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

struct Node* deletionBT(struct Node *root,int k){

             Node * temp1=root;
 
Node* keyn=NULL;
   
  if(root->left==NULL && root->right==NULL)
  {
      if(root->data==k)
      {
         
          root=NULL;
        //   return;
      }
     
       
  }
   Node* lastparent;
    queue<Node*>q;
    q.push(root);
    Node* temp;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==k)
        {
            keyn=temp;
        }
        if(temp->left)
        {
            lastparent=temp;
            q.push(temp->left);
            if(temp->left->data==k)
            {
                keyn=temp->left;
            }
        }
        if(temp->right)
        {
            lastparent=temp;
            q.push(temp->right);
            if(temp->right->data==k)
            {
                keyn=temp->right;
            }
        }
        
    }

    
    cout<<"last data\t "<<temp->data<<"\n";
    cout<<"last parent\t"<<lastparent->data<<"\n";
   if(keyn!=NULL)
   {
       int e=temp->data;
       keyn->data=e;

       cout<<keyn->data<<"\n";
       if(lastparent->right==temp)
       {
           lastparent->right=NULL;
       }
       else
       {
           lastparent->left=NULL;
       }
       delete(temp);
      
   }
    
    return temp1 ;
    
    


    

}

void inorder(Node *root){

    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{

    struct Node *root,*root1;
    root = newNode(1);
    root->left = newNode(4);
    root->right = newNode(7);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    int k=1;

    root1=deletionBT(root,k);


    inorder(root1);
    
    
     
}