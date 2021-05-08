#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


  struct  Node * create(int x){

        struct Node * newnode=new Node();
        newnode->data=x;
        newnode->left=0;
        newnode->right=0;

        return newnode;
    }
    
        
   
   int leaflevel=0;
    
    int solve(Node *root,int h){
       
         if(!root){
             return 1;
         }

         if(!root->left and !root->right){


             if(leaflevel==0){
                 leaflevel=h;
             }

             
                 return h==leaflevel;
             
         }


       return  solve(root->left,h+1) && solve(root->right,h+1);
         
      
      }
    bool check(Node *root)
    {
        //Your code here
        
        
        
           int h=1;
         return  solve(root,h);
        
      
           
        
          
       
    }

    
     

int main()
{
  struct Node* root= create(10);

  root->left=create(20);
  root->right=create(30);
   root->left->left=create(10);
    root->left->right=create(15);

     cout<<check<<"\n";
    

  




  return 0;
}  