#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node*left,*right;

};

Node *newNode(int key){

  struct  Node *newnode=new Node();

  newnode->data=key;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}
  bool find(Node*node,int k)
{
    if(node==NULL)
      return false;
    
    if(k==node->data){
      return true;
    }
    else if(node->data<k)
    {
        return find(node->right,k);
    }
    else
    {
        return find(node->left,k);
    }
    
}


  void inorder(Node*root1,Node*root2,int x,int &count){
      
      if(root1){
          
      
      
      inorder(root1->left,root2,x,count);
      
      if(find(root2,x-root1->data)){
          count++;
      }
      
       inorder(root1->right,root2,x,count);
      
      
      }
  }

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    
    
       int count=0;
       inorder(root1,root2,x,count);
       return count;
}

int main(){
    struct Node *root1,*root2;
 
    root1=newNode(5);
    root1->left=newNode(3);
    root1->right=newNode(7);
    root1->left->left=newNode(2);
    root1->left->right=newNode(4);
    root1->right->left=newNode(6);
    root1->right->right=newNode(8);


      root2=newNode(10);
    root2->left=newNode(6);
    root2->right=newNode(15);
    root2->left->left=newNode(3);
    root2->left->right=newNode(8);
    root2->right->left=newNode(11);
    root2->right->right=newNode(18);

     int x=16;
    cout<<countPairs(root1,root2, x)<<"\n";

   

    
    return 0;
}