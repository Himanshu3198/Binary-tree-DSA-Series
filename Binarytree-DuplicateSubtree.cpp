//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printAllDups(Node* root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}// } Driver Code Ends


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
//   string solve(Node*root,unordered_map<string,int>&mp){
      
//       if(!root) return "";
      
//       string s=to_string(root->data,mp)+""+solve(root->left,mp)+""+solve(root->right,mp);
      
//       mp[s]++;
//       if(mp[s]==2){
//           cout<<root->data<<" ";
//       }
//       return s;
//   }


string inorder(Node* node, unordered_map<string, int>& m,vector<int>&ans)
{
    if (!node)
        return "";
 
    string str = "(";
    str += inorder(node->left, m,ans);
    str += to_string(node->data);
    str += inorder(node->right, m,ans);
    str += ")";
 
  
    if (m[str] == 1){
           // cout << node->data << " ";
        ans.push_back(node->data);
    }
      
 
    m[str]++;
 
    return str;
}
 
void printAllDups(Node* root)
{
    // Code here
    
    vector<int>ans;
         
       unordered_map<string, int> m;
    inorder(root, m,ans);
    
    sort(ans.begin(),ans.end());
    
    if(ans.size()==0){
        cout<<-1;
            return;
        
    }

    
    for(auto it:ans){
        cout<<it<<" ";
    }
}