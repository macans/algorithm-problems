/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Makea Valid Parentheses
 */

// @lc code=start

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = 0, r = 0, i = 0;
        while( i < s.length()){
            if(s[i] == '('){
                ++l;
            }
            if(s[i] == ')'){
                if(l > 0) {
                    --l;
                }
                else{
                    ++r;
                }
            }
            ++i;
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')' && r-- > 0) s[i] = '@';
        }
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '(' && l-- > 0) s[i] = '@'; 
        }
        string res;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '@') res.push_back(s[i]);
        }
        return res;
    }
};

// @lc code=end

