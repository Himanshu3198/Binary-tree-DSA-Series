/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        
        if(!root) return "";
        
        string s="";
        
        queue<TreeNode *>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            
            TreeNode *curr=q.front();
            q.pop();
            
            if(curr==NULL){
                s.append("#,");
            }else{
                s.append(to_string(curr->val)+',');
            }
            
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        
        string str;
        getline(s,str,',');
        
        TreeNode *root=new TreeNode(stoi(str));
         queue<TreeNode*>q;
         q.push(root);
        
         while(!q.empty()){
             
               TreeNode *curr=q.front();
                q.pop();
             
             getline(s,str,',');
             
             if(str=="#"){
                 curr->left=NULL;
             }else {
                 
                 curr->left=new TreeNode(stoi(str));
                 q.push(curr->left);
             }
             
             getline(s,str,',');
             
             if(str=="#"){
                 curr->right=NULL;
             }else{
                 curr->right=new TreeNode(stoi(str));
                 q.push(curr->right);
             }
         }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// java version

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty()){

            TreeNode curr = q.poll();
            if(curr == null){
                sb.append("#");
            }else{
                String val = String.valueOf(curr.val);
                sb.append(val);
            }
            sb.append(",");

            if(curr != null){
                q.offer(curr.left);
                q.offer(curr.right);
            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {

        String[] arr = data.split(",");
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode root = null;
        int idx = 0;
        if(!arr[idx].equals("#")){
            TreeNode newNode = new  TreeNode(Integer.parseInt(arr[idx++]));
            q.offer(newNode);
            root = newNode;
        }
        while(!q.isEmpty() && idx <arr.length){
            
            TreeNode curr = q.poll();
            if(!arr[idx].equals("#")){
                curr.left = new TreeNode(Integer.parseInt(arr[idx]));
                q.offer(curr.left);
            }
            idx++;

            if(idx < arr.length && !arr[idx].equals("#")){
                curr.right = new TreeNode(Integer.parseInt(arr[idx]));
                q.offer(curr.right);
            }
            idx++;
        }

        return root;

       
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
