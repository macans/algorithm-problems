/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-12-2 13:16:01
   *  File : leetcode-hard-44-wildcard-matching.cc
   ********************************************/
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, lastI = 0;
        while (i < s.size()) {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                star = j++;
                lastI = i;
            } else if (star != -1) {
                j = star + 1;
                i = ++lastI;
            } else {
                return false;
            }
        }
        while(j < p.size() && p[j] == '*') j++;
        return j == p.size();
    }
};

int main(){
    Solution s;
    string a = "adceb";
    string b = "*a*b";
    cout << s.isMatch(a, b) << endl;
	return 0;
}
