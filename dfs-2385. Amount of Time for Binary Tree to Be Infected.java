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
    int ans;
    TreeNode infectedNode;

    private void dfs(TreeNode root,int start,Map<Integer,TreeNode> parent){
        if(root == null) return;

        if(root.val == start) infectedNode = root;

        if(root.left != null){
            parent.put(root.left.val,root);
            dfs(root.left,start,parent);
        }
        if(root.right != null){
            parent.put(root.right.val,root);
            dfs(root.right,start,parent);
        }
    }

    private void timeTaken(TreeNode root,Map<Integer,TreeNode>parent,Map<Integer,Integer>visited,int time){

        if(root == null) return;
        if(visited.containsKey(root.val)) return;

        visited.put(root.val,1);
        ans = Math.max(ans,time);

        timeTaken(root.left,parent,visited,time+1);
        timeTaken(root.right,parent,visited,time+1);
        timeTaken(parent.get(root.val),parent,visited,time+1);
    }
    public int amountOfTime(TreeNode root, int start) {
        
        ans = 0;
        Map<Integer,TreeNode> parent = new HashMap<>();
        Map<Integer,Integer> visited = new HashMap<>();
        parent.put(root.val,null);
        dfs(root,start,parent);
        timeTaken(infectedNode,parent,visited,0);

        return ans;

    }
}
