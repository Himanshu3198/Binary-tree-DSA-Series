
/* C program for boundary traversal 
of a binary tree */
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
};


void leftTree(Node * root,vector<int>&ans){

    if(root==NULL){
        return;
    }

    if(root->left!=NULL){
         ans.push_back(root->data);
    leftTree(root->left,ans);
    }

    else if(root->right!=NULL){
    ans.push_back(root->data);
    leftTree(root->right,ans);
    }
 
}

void leafTree(Node *root,vector<int>&ans){

   if(!root){
       return;
   }
    if(root->left!=NULL){

        leafTree(root->left,ans);
    }
    if(root->left==NULL and root->right==NULL){

          ans.push_back(root->data);
    }

      if(root->right!=NULL){

        leafTree(root->right,ans);
    }



}

void rightTree(Node *root,vector<int>&ans){
 
   if(!root){
       return;
   }
    if(root->right){
        rightTree(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left){
           rightTree(root->left,ans);
        ans.push_back(root->data);
    }
}
void printBoundary(struct Node* root)
{
  
     
     
     vector<int>ans;

      ans.push_back(root->data);

     leftTree(root->left,ans);
     leafTree(root,ans);

     rightTree(root->right,ans);
     
     

     

     
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<"\n";
     

}

// A utility function to create a node
struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);

    return 0;
}
