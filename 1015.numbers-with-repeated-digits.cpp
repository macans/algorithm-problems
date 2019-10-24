/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Numbers With Repeated Digits
 *
 * https://leetcode.com/problems/numbers-with-repeated-digits/description/
 *
 * algorithms
 * Hard (29.61%)
 * Total Accepted:    2.2K
 * Total Submissions: 6.4K
 * Testcase Example:  '20'
 *
 * Given a positive integer N, return the number of positive integers less than
 * or equal to N that have at least 1 repeated digit.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 20
 * Output: 1
 * Explanation: The only positive number (<= 20) with at least 1 repeated digit
 * is 11.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 100
 * Output: 10
 * Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are
 * 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 1000
 * Output: 262
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 * 
 */
#include <iostream>
using namespace std;

class Solution {

inline int permute(int m, int n){
    int res = 1;
    while(n){
        res *= m;
        m--;
        n--;
    }
    return res;
}
public:
    int countNoDup(int n, int k){
        
    }
    int numDupDigitsAtMostN(int n) {
        int k = 1;
        while(n >= k){
            k *=10;
        }
        --k;
        int numNoDup = countNoDup(n, k);
        return n - numNoDup;
    }
};

int main(){
    Solution s;
    cout << s.numDupDigitsAtMostN(10) << endl;
}
