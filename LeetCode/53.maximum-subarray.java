/*
 * @lc app=leetcode id=53 lang=java
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int len = nums.length;
        int[] sum = new int[len];
        for(int i = 0; i < len; i++) {
            sum[i] = nums[i];
        }
        int ans = sum[0];
        for(int i = 1; i < len; i++) {
            sum[i] = Math.max(sum[i - 1] + nums[i], sum[i]);
            ans = Math.max(sum[i], ans);
        }
        return ans;
    }
}
// @lc code=end

