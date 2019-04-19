/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.08%)
 * Total Accepted:    191.9K
 * Total Submissions: 633.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        int* ans = new int[n + m];
        for(int i = 0; i < n + m; i++){
            ans[i] = 0;
        }
        int *a = new int[n], *b = new int[m];
        for(int i = 0; i < n; i++){
            a[i] = num1[n - i - 1] - '0';
        }
        for(int i = 0; i < m; i++){
            b[i] = num2[m - i - 1] - '0';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i + j] += a[i] * b[j];
                if(i + j > 0){
                    ans[i + j] += ans[i + j - 1] / 10;
                    ans[i + j - 1] %= 10;
                }
            }
        }
        string res;
        bool not0 = false;
        if(ans[n + m - 2] >= 10){
            res.push_back(ans[n + m - 2] / 10 + '0');
            ans[n + m - 2] %= 10;
            not0 = true;
        }
        for(int i = n + m - 2; i >= 0; i--){
            if(ans[i] != 0) not0 = true;
            if(not0) res.push_back(ans[i] + '0');
        }
        if(!not0) return "0";
        return res;
    }
};

