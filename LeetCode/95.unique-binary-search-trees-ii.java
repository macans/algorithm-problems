/*
 * @lc app=leetcode id=95 lang=java
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
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
    private static final List<TreeNode> EMPTY_NODES;
    static {
        EMPTY_NODES = new ArrayList<>();
        EMPTY_NODES.add(null);
    }
   
    List<TreeNode> buildTree(int from, int to) {
        if(from > to) {
            return EMPTY_NODES;
        }
        if(from == to) {
            return Arrays.asList(new TreeNode(from));
        }
        List<TreeNode> result = new ArrayList<>();
        for(int i = from; i <= to; i++) {
            List<TreeNode> leftTree = buildTree(from, i - 1);
            List<TreeNode> rightTree = buildTree(i + 1, to);
            for(int p = 0; p < leftTree.size(); p++) {
                for(int q = 0; q < rightTree.size(); q++){
                    TreeNode root = new TreeNode(i);
                    root.left = leftTree.get(p);
                    root.right = rightTree.get(q);
                    result.add(root);
                }
            }
        }
        return result;
    }
    public List<TreeNode> generateTrees(int n) {
        return buildTree(1, n);
    }
}
// @lc code=end


