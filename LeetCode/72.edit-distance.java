/*
 * @lc app=leetcode id=72 lang=java
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
    public int minDistance(String word1, String word2) {
        // dp[i][j] 表示 word1 的前 i 位 和 word2前j位的distance
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1
        // dp[i][j] = dp[i - 1][j - 1] + (s[i] == s[j] ? 0 : 1)

        /*
         * dp[i][0] = s1[i] == s2[0] ? i - 1 ?
         * dp[0][i] == s1
         */
        char[] s1 = word1.toCharArray();
        char[] s2 = word2.toCharArray();
        if (s1.length == 0) {
            return s2.length;
        }
        if (s2.length == 0) {
            return s1.length;
        }

        int[][] dp = new int[s1.length][s2.length];
        dp[0][0] = s1[0] == s2[0] ? 0 : 1;
        for (int i = 0; i < s1.length; i++) {
            for (int j = 0; j < s2.length; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0) {
                    dp[i][j] = s1[i] == s2[j] ? j : (dp[i][j - 1] + 1);
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = s1[i] == s2[j] ? i : (dp[i - 1][j] + 1);
                    continue;
                }
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + (s1[i] == s2[j] ? 0 : 1));
            }
        }
        return dp[s1.length - 1][s2.length - 1];
    }
}
// @lc code=end
