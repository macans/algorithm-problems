/*
 * @lc app=leetcode id=392 lang=java
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
    public boolean isSubsequence(String s, String t) {
        int p = 0, q = 0;
        while(p < s.length() && q < t.length()) {
            if(s.charAt(p) == t.charAt(q)) {
                p++;
                q++;
            } else {
                q++;
            }
        }
        return p == s.length();
    }
}
// @lc code=end

