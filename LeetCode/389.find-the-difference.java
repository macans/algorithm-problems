/*
 * @lc app=leetcode id=389 lang=java
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
    public char findTheDifference(String s, String t) {
        int[] cnt1 = new int[26], cnt2 = new int[26];
        for (int i = 0; i < s.length(); i++) {
            ++cnt1[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < t.length(); i++) {
            ++cnt2[t.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                return (char)(i + 'a');
            }
        }
        return ' ';
    }
}
// @lc code=end
