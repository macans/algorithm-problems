/*
 * @lc app=leetcode id=918 lang=java
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int len = nums.length;
        int[] circles = new int[len * 2 - 1];
        for (int i = 0; i < len; i++) {
            circles[i] = nums[i];
        }
        for (int i = len; i < len * 2 - 1; i++) {
            circles[i] = nums[i - len];
        }
        int clen = len * 2 - 1;
        int ans = Integer.MIN_VALUE, left = 0, right = 0, cur = circles[0];
        while (left < clen) {
            System.out.println(left + ", " + right);
            ans = Math.max(ans, cur);
            if (right < left) {
                ++right;
                cur += circles[right];
            } else if (right - left >= len - 1) {
                cur -= circles[left];
                ++left;
            } else if (right < clen - 1 && cur + circles[right + 1] > 0) {
                ++right;
                cur += circles[right];
            } else {
                cur -= circles[left];
                ++left;
            }

        }
        return ans;
    }
}
// @lc code=end
