/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        char[] ss = s.toCharArray();
        boolean[][] f = new boolean[n][n];
        int ans = 1, pos = 0;
        for (int i = 0; i < n; i++) {
            f[i][i] = true;
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 0; i < n; i++) {
                if(i + j - 1 >= n) {
                    break;
                }
                if (j == 2 && ss[i] == ss[i + 1]) {
                    f[i][i + j - 1] = true;
                }
                if (j != 2 && f[i + 1][i + j - 2] && ss[i] == ss[i + j - 1]) {
                    f[i][i + j - 1] = true;
                }
                if (f[i][i + j - 1]) {
                    ans = j;
                    pos = i;
                }
            }
        }
        return s.substring(pos, pos + ans);
    }
}
// @lc code=end
