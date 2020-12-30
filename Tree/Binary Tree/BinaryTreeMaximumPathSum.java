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
    private int max = Integer.MIN_VALUE;
    
    public int maxPathSum(TreeNode root) {
        maxPathSumUtil(root);
        return max;
    }
    
    public int maxPathSumUtil(TreeNode root) {
        if(root == null) {
            return 0;
        }
        
        int left = maxPathSumUtil(root.left);
        int right = maxPathSumUtil(root.right);
        
        int tmp = Integer.max(Integer.max(left, right)+root.val, root.val);
        int ans = Integer.max(tmp, left+right+root.val);
        max = Integer.max(ans, max);
        
        return tmp;
    }
}