// 429. N-ary Tree Level Order Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
     
        
        queue<Node*>q;
        
        
        
        q.push(root);
        
        vector<vector<int>>res;
        
        if(!root){
            return res;
        }
        
     
        
        while(!q.empty()){
            
            
            
            
                vector<int>v;
            
            int size=q.size();
            
              for(int i=0;i<size;i++){
                  
                   
                    Node *cur=q.front();
               q.pop();
                  
                  v.push_back(cur->val);
                  
                   
                  for(int j=0;j<cur->children.size();j++){
                      
                      q.push(cur->children[j]);
                  }
                  
                
              }
              
               if(v.size()>0){
                    res.push_back(v);
               }
             
            
            
              
        }
        
        return res;
    }
};
