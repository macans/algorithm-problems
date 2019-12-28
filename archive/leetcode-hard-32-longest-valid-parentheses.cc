/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-11-24 22:44:28
   *  File : leetcode-hard-32-longest-valid-parentheses.cc
   ********************************************/
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> a;
        int ans = 0, last = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') a.push(i);
            else if(!a.empty()){
                int j = a.top(); a.pop();
                if(a.empty()){
                    ans = max(ans, i - last);
                }
                else{
                    ans = max(ans, i - a.top());
                }
            }
            else last = i;
        }
        return ans;
    }
};
int main(){

	return 0;
}
