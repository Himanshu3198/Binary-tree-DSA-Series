#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int key)
{

    struct Node *newnode = new Node();
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void flatten(Node *root)
{
   

    if (root == NULL || root->left == NULL &&
                            root->right == NULL)
    {
        return;
    }

    // if root->left exists then we have
    // to make it root->right
    if (root->left != NULL)
    {

        // move left recursively
        flatten(root->left);

        // store the node root->right
        struct Node *tmpRight = root->right;
        root->right = root->left;
        root->left = NULL;

        // find the position to insert
        // the stored value
        struct Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }

        // insert the stored value
        t->right = tmpRight;
    }

    // now call the same function
    // for root->right
    flatten(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    struct Node *root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->right=newNode(5);
    root->left->right->left=newNode(6);
    root->left->right->right=newNode(9);
    root->left->right->right->left=newNode(10);

     root->left->right->left->right=newNode(7);
     root->left->right->left->right->left=newNode(8);


    // root->right->left = newNode(2);
    // root->right->left->right = newNode(5);

    flatten(root);
    inorder(root);
    return 0;
}