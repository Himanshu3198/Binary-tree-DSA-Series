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





   
  
  
   void solve(Node *root,int &maxSum,int &maxlen,int sum,int len){
      
      
      if(!root){
         

          if(maxlen<len){
              maxlen=len;
              maxSum=sum;
          }
          else if(maxlen==len and maxSum<sum){
               maxSum=sum;
          }
          return;
      }
      
    
    
      
     solve(root->left,maxSum,maxlen,sum+root->data,len+1);
        solve(root->right,maxSum,maxlen,sum+root->data,len+1);
    
  }
  
  
  
    
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	
	
	  int maxSum=INT_MIN,len=0,maxlen=0,sum=0;
	  
	  solve(root,maxSum,maxlen,len,sum);
	  
	  return maxSum;
}
    
    
     


    
     

int main()
{
  struct Node* root= create(4);

  root->left=create(2);
  root->right=create(5);
   root->left->left=create(7);
    root->left->right=create(1);
      root->left->right->left=create(6);

       root->right->left=create(2);
        root->right->right=create(3);





    cout<<sumOfLongRootToLeafPath(root);

  cout<<"\n";

    

  




  return 0;
}  