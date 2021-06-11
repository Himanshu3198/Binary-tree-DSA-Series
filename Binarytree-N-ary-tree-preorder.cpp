// 589. N-ary Tree Preorder Traversal

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
    vector<int> preorder(Node* root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        
        
    stack<Node*>nodes;
        
        nodes.push(root);
        
        while(!nodes.empty()){
            
            Node *curr=nodes.top();
            
              ans.push_back(curr->val);
              nodes.pop();
            
            int size=curr->children.size();
            
            for(int i=size-1;i>=0;i--){
                
                nodes.push(curr->children[i]);
            }
        
        
        }
        
        return ans;
        
    }
};
