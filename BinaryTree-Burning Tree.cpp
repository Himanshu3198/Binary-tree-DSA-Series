
//   time complexity O(n)+O(n)+O(log(n) ~O(n)
//   space compexity O(n)+O(n) ~O(n)
class Solution {
  public:
         Node *source;
         unordered_map<Node*,Node*>getParent;
        
         void solve(Node *root,int target){
             
             if(!root) return;
             if(root->data==target) source=root;
             
             if(root->left) getParent[root->left]=root;
             if(root->right) getParent[root->right]=root;
             solve(root->left,target);
             solve(root->right,target);
         }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
           getParent[root]==root;
           solve(root,target);
            
            if(root and !root->left and !root->right) return 0;
            
           queue<Node*>q;
           set<Node*>vis;
           q.push(source);
           int time=0;
           while(!q.empty()){
               
               int size=q.size();
               time++;
               while(size--){
                   
                   Node *curr=q.front();
                              q.pop();
                              
                    if(vis.count(curr)==1) break;  
                    vis.insert(curr);
                    
                    if(curr->left){
                       
                       if((curr->left->left or curr->left->right) and !vis.count(curr->left)){
                           
                           q.push(curr->left);
                       }
                   }
                   if(curr->right){
                        if((curr->right->left or curr->right->right) and !vis.count(curr->right)){
                           
                           q.push(curr->right);
                       }
                       
                   }
                   
                   if(getParent[curr]){
                       
                       if(vis.count(getParent[curr])==0){
                           q.push(getParent[curr]);
                       }
                   }
                   
               }
               
               
           }
         
           return time;
           
           
    }
