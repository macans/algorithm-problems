/*
 * @lc app=leetcode id=45 lang=java
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = Integer.MAX_VALUE;
        }
        f[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j <= i + nums[i] && j < n; j++) {
                f[j] = Math.min(f[j], f[i] + 1);
            }
        }
        return f[n - 1];
    }
}
// @lc code=end
