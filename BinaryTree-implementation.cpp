// simple implementation of binary tree using recursion in cpp
// time Complexity  O(h) h:height of tree

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

void PreOrder(struct node *root)
{

    if (root != NULL)
    {

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    
}

void inOrder(struct node *root){

    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);

        
    }
    
}

void postOrder(struct node *root){
    if(root!=NULL){
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    }
   
}
int main()
{

    struct node *root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    cout << "preorder\n";
    PreOrder(root);
     cout<<"\n";
    inOrder(root);
     cout<<"\n";

    postOrder(root);
    cout<<"\n";
    
    return 0;
}

// expected output :
// 1 2 4 3
// 4 2 1 3
// 4 2 3 1
