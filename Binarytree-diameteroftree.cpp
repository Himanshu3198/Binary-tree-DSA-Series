// simple implementation diameter of binary tree using recursion in cpp
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
  int ma=INT_MIN;
int dim(struct node *root){
    if(!root){
        return 0;
    }

    int x=dim(root->left);
    int y=dim(root->right);
    ma=max(ma,x+y+1);

    return max(x,y)+1;

}
 int diameter(struct node * root){
       

     
       dim(root);

       return ma;
    
    
    }
int main()
{

    struct node *root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    cout<<diameter(root)<<"\n";
    
    cout<<"\n";
}