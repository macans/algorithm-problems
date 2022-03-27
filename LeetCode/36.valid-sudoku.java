import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode id=36 lang=java
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<Integer> bucket = new HashSet<>();

        int x = 0, y = 0;
        for (int k = 0; k < 9; k++) {
            bucket.clear();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[x + i][y + j] == '.') {
                        continue;
                    }
                    int val = board[x + i][y + j];
                    if (bucket.contains(val)) {
                        return false;
                    }
                    bucket.add(val);
                }
            }
            x += 3;
            if(x >= 9) {
                x = 0;
                y += 3;
            }
        }
        
        for (int row = 0; row < 9; row++) {
            bucket.clear();
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    continue;
                }
                int val = board[row][col] - '0';
                if (bucket.contains(val)) {
                    return false;
                }
                bucket.add(val);
            }
        }

        for (int col = 0; col < 9; col++) {
            bucket.clear();
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') {
                    continue;
                }
                int val = board[row][col] - '0';
                if (bucket.contains(val)) {
                    return false;
                }
                bucket.add(val);
            }
        }

        return true;
    }
}
// @lc code=end
