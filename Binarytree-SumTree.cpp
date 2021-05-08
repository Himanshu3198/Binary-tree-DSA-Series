#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


  struct  Node * create(int x){

        struct Node * newnode=new Node();
        newnode->data=x;
        newnode->left=0;
        newnode->right=0;

        return newnode;
    }
    
    
      int sum (Node * root){
          
          if(!root){
              return 0;
          }
          return sum(root->left)+sum(root->right) +root->data;
      }
    bool isSumTree(Node* root)
    {
         // Your code here
         
        int x=root->data;
         int a=sum(root->left);
         int b=sum(root->right);
         
         if(a+b==x){
             return 1;
         }
         return 0;
          
    }


  void  inorder(Node *root){
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }


    
     

int main()
{
  struct Node* root= create(10);

  root->left=create(20);
  root->right=create(30);
   root->left->left=create(10);
    root->left->right=create(10);

 //   inorder(root);
   cout<<isSumTree(root);
    

  




  return 0;
}  