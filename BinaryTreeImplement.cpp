// implementation of binary tree using structure and classes
#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    
};
Node * newNode(int x){
        Node *temp=new Node;
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;

        return temp;
    
           
}

class BinaryTreeImplement{

    public:
  
  
    void display(Node * root);  //constructor
    

};

void BinaryTreeImplement::display(Node *root){
         if(!root) return;
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
     
      }
int main(){

    Node *root= newNode(1);
    root->left= newNode(4);
    root->left->left=newNode(4);
    root->left->right=newNode(2);

     BinaryTreeImplement sol;
     sol.display(root);
    return 0;

}