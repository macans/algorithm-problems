/*
 * @lc app=leetcode id=393 lang=java
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
    public boolean validUtf8(int[] data) {
        int[] m = new int[5];
        m[2] = 6;
        m[3] = 14;
        m[4] = 30;
        int i = 0;
        boolean valid = false;
        while(i < data.length) {
            valid = false;
            if((data[i] >> 7) == 0) {
                valid = true;
                ++i;
                continue;
            }
            for(int j = 2; j <= 4; j++) {
                if((data[i] >> (8 - j - 1)) == m[j]) {
                    valid = true;
                    if(i + j - 1 >= data.length) {
                        valid = false;
                        break;
                    }
                    for(int k = i + 1; k < i + j; k++) {
                        if((data[k] >> 6) != 2) {
                            valid = false;
                            break;
                        }
                    }
                    i += j;
                    break;
                }
            }
            if(!valid) {
                break;
            }
        }
        return valid;
    }
}
// @lc code=end

