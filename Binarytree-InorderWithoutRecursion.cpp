// inorder traversal without recusrion | using stack in cpp
// Time Complexity: O(h)
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node *newNode(int key){
  
   struct node *newnode=new node();
   newnode->data=key;
   newnode->left=NULL;
   newnode->right=NULL;

} 

void inOrder(struct node *root){

     stack<node*>s;
     node *curr=root;
     while(curr!=NULL || s.empty()==false){
         while(curr!=NULL){

             s.push(curr);
             curr=curr->left;
         }

    curr=s.top();
       s.pop();

       cout<<curr->data<<" ";
       curr=curr->right;

     }

}




int main(){

    struct node *root;
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    inOrder(root);

    return 0;

}