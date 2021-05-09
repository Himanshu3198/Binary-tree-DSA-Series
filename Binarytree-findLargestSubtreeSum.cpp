// Find largest subtree sum in a tree
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
    
    
      int sum (Node * root,int &maxSum){
          
          if(!root){
              return 0;
          }

          int x=root->data;

          int a=sum(root->left,maxSum);
          int b=sum(root->right,maxSum);

           int ans=x+a+b;

           if(ans>maxSum){
               maxSum=ans;
           }
           return ans;
          
      }
    void largestSumTree(Node* root)
    {
         // Your code here
         
            int maxSum=INT_MIN;

           cout<< sum(root,maxSum);
          
    }


  void  inorder(Node *root){
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }


    
     

int main()
{
  struct Node* root= create(1);

  root->left=create(-2);
  root->right=create(3);
   root->left->left=create(4);
    root->left->right=create(5);

    root->right->left=create(-6);
    root->right->right=create(2);
 //   inorder(root);
    largestSumTree(root);
    

  




  return 0;
}  