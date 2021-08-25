// 559. Maximum Depth of N-ary Tree
// BFS
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
    int maxDepth(Node* root) {
        
        if(!root){
            return NULL;
        }
         queue<Node*>q;
        
          q.push(root);
        
        int maxlevel=0;
        
        int level=0;
        
        while(!q.empty()){
            
            int size=q.size();
               level++;
            while(size--){
             
                Node*  curr=q.front();
                q.pop();
                
                for(Node* child:curr->children){
                    
                    q.push(child);
                }
            }
            
        }
        return level;
    }
};
