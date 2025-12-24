/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    private boolean isLeaf(TreeNode root){
        return (root.left == null && root.right == null);
    }

    private void addLeft(TreeNode root,List<Integer> res){

        while(root != null){

            if(!isLeaf(root)) res.add(root.val);
            root = root.left != null?root.left:root.right;
        }
    }

    private void addRight(TreeNode root,List<Integer>res){
       
        Stack<Integer> st = new Stack<>();
        while(root != null){
            if(!isLeaf(root)) st.push(root.val);
            root = root.right != null?root.right:root.left;
        }
        while(!st.isEmpty()){
            res.add(st.pop());
        }
    }

    private void addLeaf(TreeNode root,List<Integer> res){
        if(root == null) return;
        if(isLeaf(root)) res.add(root.val);
        addLeaf(root.left,res);
        addLeaf(root.right,res);  
    }
    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        res.add(root.val);

        addLeft(root.left,res);
        if(!isLeaf(root))
         addLeaf(root,res);
        addRight(root.right,res);

        return res;
        
    }
}
