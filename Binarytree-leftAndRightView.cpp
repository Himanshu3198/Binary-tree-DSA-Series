// left view and right view of binary tree in cpp
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

//  
void leftView(bool *levels,node *root,int currlevel){

    if(!root){
        return;
    }
    if(levels[currlevel]==false){
        levels[currlevel]=true;
        cout<<root->data<<" ";
    }
    leftView(levels,root->left,currlevel+1);
    leftView(levels,root->right,currlevel+1);

}
void rightView(bool *levels,node *root,int currlevel){

    if(!root){
        return;
    }
    if(levels[currlevel]==false){
        levels[currlevel]=true;
        cout<<root->data<<" ";
    }

    rightView(levels,root->right,currlevel+1);
    rightView(levels,root->left,currlevel+1);
    

}





int main(){

    struct node *root;
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    bool levels[100]={false};
    // leftView(levels,root,0);
    rightView(levels,root,0);

    return 0;

}