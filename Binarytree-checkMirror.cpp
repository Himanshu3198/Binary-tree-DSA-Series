#include<bits/stdc++.h>
using namespace std;


struct Node{

    int data;
    struct Node *left;
    struct Node *right;
};


Node *newNode(int key){

    struct Node *newnode=new Node;
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

bool isMirror(Node *a,Node *b){

    if(a==NULL && b==NULL){
        return true;
    } 
    else if(a==NULL || b==NULL){
        return false;
    }

    else if(a->data==b->data){
        return isMirror(a->left,b->right) && isMirror(a->right,b->left);
    }
    else{
        return false;
    }

  
}
int main(){

     struct Node *root1,*root2;

     root1=newNode(1);
     root1->left=newNode(2);
     root1->right=newNode(3);


     root2=newNode(1);
     root2->left=newNode(3);
     root2->right=newNode(2);

     if(isMirror(root1,root2)){
         cout<<"yes tree are mirror to each other\n";
     }
     else{
         cout<<"No\n";
     }
    return 0;
}