// level order traversal using queue
// time complexiy O(n)
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left=NULL ,*right=NULL;
};



struct node *Node(int x){
    struct node *newnode=new node;
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
}


void levelOrder(struct node *root){

    if(root==NULL){
        return;
    }
    else{
         queue<node*> q;
         q.push(root);

         while(!q.empty()){

             node *current=q.front();
               q.pop();

             cout<<current->data<<" ";
             if(current->left!=NULL){
                 q.push(current->left);
             }
             if(current->right!=NULL){
                 q.push(current->right);
             }

         }
    }
}


int main(){


    struct node *root;
    root=Node(1);
    root->left=Node(2);
    root->right=Node(3);
    root->left->left=Node(4);
    root->left->right=Node(5);
    root->right->left=Node(6);
    root->right->right=Node(7);
    root->left->left->left=Node(8);
    root->left->left->right=Node(9);
    root->right->left->right=Node(10);
    levelOrder(root);
    return 0;

}


// expected output : 1 2 3 4 5 6 7 8 9 10