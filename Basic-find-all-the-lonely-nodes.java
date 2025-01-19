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
    List<Integer> ans = new ArrayList<>();
    public void solve(TreeNode root){
        if(root == null) return;
        if(root.left != null && root.right == null){
          ans.add(root.left.val);
        } 
        else if(root.right != null && root.left == null){
                ans.add(root.right.val);
        } 
        solve(root.left);
        solve(root.right);
    }
    public List<Integer> getLonelyNodes(TreeNode root) {
          solve(root);
          return ans;
    }
}
