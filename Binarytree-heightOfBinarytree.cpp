// simple implementation height of binary tree using recursion in cpp
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

 int height(struct node * root){
          if (root == NULL) {
        return 0;
    }
    else {
        int left = height (root->left);
        int right = height (root->right);

        int height = (left < right) ? right+1 : left+1;
        return height;
    }
    
    }
int main()
{

    struct node *root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    cout<<height(root)<<"\n";
    
    cout<<"\n";
}