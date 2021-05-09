// left view and right view of binary tree in cpp
// Time Complexity: O(h)
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int key)
{

    struct node *newnode = new node();
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
}

bool printAncestor(node *root, int val, int &k)
{

    if (!root)
    {
        return false;
    }

     

    if (root->data == val)
    {
         if(k>0){
         k--;
        }

        if (k == 0)
        {
            cout << root->data << " ";
           
        }

         return true;
          
    }

    if (printAncestor(root->left, val, k) or printAncestor(root->right, val, k))
    {
         if(k>0){
         k--;
        }
        if (k == 0)
        {
            cout << root->data << " ";
           
        }

         return true;


    
    }
    return false;
}

int main()
{

    struct node *root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int k = 2;
    printAncestor(root, 5, k);

    return 0;
}