/*
 * @lc app=leetcode id=73 lang=java
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> rows = new HashSet<>();
        Set<Integer> cols = new HashSet<>();
        int n = matrix.length;
        if(n < 1) {
            return;
        }
        int m = matrix[n - 1].length;
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[i].length; j++) {
                if(matrix[i][j] == 0) {
                    rows.add(i);
                    cols.add(j);
                }
            }
        }
        
        Iterator<Integer> it = rows.iterator();
        while(it.hasNext()) {
            int k = it.next();
            for(int i = 0; i < m; i++) {
                matrix[k][i] = 0;
            }
        }
        it = cols.iterator();
        while(it.hasNext()) {
            int k = it.next();
            for(int i = 0; i < n; i++) {
                matrix[i][k] = 0;
            }
        }
        return;
    }
}
// @lc code=end

