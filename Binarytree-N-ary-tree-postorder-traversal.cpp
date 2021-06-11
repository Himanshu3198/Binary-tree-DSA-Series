// 590. N-ary Tree Postorder Traversal


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
    vector<int> postorder(Node* root) {
           vector<int> ans;
        if(!root){
            return ans;
        }
        stack<Node*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            Node* curr = nodes.top();
            ans.push_back(curr->val);
            nodes.pop();
            int size= curr->children.size();
            for(int idx=0;idx<size;idx++){
                nodes.push(curr->children[idx]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};
