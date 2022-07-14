/*
 * @lc app=leetcode id=390 lang=java
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
    public int lastRemaining(int n) {
        int remainNum = n;
        int left = 1, right = n;
        int times = 1;
        while (remainNum != 1) {
            if ((times & 1) == 1) {
                if((right - left) % (1 << times) == 0) {
                    right = Math.max(left, right - (1 << (times - 1)));
                }
                left = left + (1 << (times - 1));
            } else {
                if((right - left) % (1 << times) == 0) {
                    left = Math.min(right, left + (1 << (times - 1)));
                }
                right = right - (1 << (times - 1));
            }
            times++;
            remainNum >>= 1;
        }
        return left;
    }
}
// @lc code=end
