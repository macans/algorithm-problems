/*
 * @lc app=leetcode id=1248 lang=java
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int[] oddIndex = new int[nums.length];
        int len = nums.length;
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if((nums[i] & 1) == 1) {
                oddIndex[cnt++] = i;
            }
        }

        if(cnt < k) {
            return 0;
        }
        int left = 0, right = k - 1;
        int lastLeft = -1, nextRight;
        int ans = 0;
        while(right < cnt) {
            nextRight = right + 1 < cnt ? oddIndex[right + 1] : len;
            ans += (oddIndex[left] - lastLeft) * (nextRight - oddIndex[right]);
            lastLeft = oddIndex[left];
            left++;
            right++;
        }
        return ans;
    }
}
// @lc code=end

