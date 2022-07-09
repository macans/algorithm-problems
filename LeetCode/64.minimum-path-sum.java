/*
 * @lc app=leetcode id=64 lang=java
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] f = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    f[i][j] = grid[i][j];
                    continue;
                }
                f[i][j] = Integer.MAX_VALUE;
                if (i != 0) {
                    f[i][j] = Math.min(f[i - 1][j] + grid[i][j], f[i][j]);
                }
                if (j != 0) {
                    f[i][j] = Math.min(f[i][j - 1] + grid[i][j], f[i][j]);
                }
            }
        }
        return f[n - 1][m - 1];
    }
}
// @lc code=end
