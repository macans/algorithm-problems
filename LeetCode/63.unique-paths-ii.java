/*
 * @lc app=leetcode id=63 lang=java
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        f[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    f[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i != 0) {
                    f[i][j] += f[i - 1][j];
                }
                if (j != 0) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
}
// @lc code=end
