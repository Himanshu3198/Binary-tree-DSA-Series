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

    Map<Long,Integer> map = new HashMap<>();
   
    private int solve(TreeNode root, int target,long curr){

        if(root == null) return  0;

        curr += root.val;
        int path = map.getOrDefault(curr-target,0);
        map.put(curr,map.getOrDefault(curr,0)+1);

        path += solve(root.left,target,curr);
        path += solve(root.right,target,curr);

        map.put(curr,map.getOrDefault(curr,0)-1);

        return path;
    
    }
    public int pathSum(TreeNode root, int targetSum) {
          map.put(0L,1);
          return solve(root,targetSum,0L);
    }
}
