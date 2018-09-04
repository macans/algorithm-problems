/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-9-5 00:39:01
   *  File : leetcode-medium-898-Bitwise ORs of Subarrays.cc
   ********************************************/
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int> &A) {
        unordered_set<int> ans, a, b;
        for(int i : A){
            for(int x: a){
                b.insert(x | i);
            }
            b.insert(i);
            for(int x : b){
                ans.insert(x);
            }
            a = b;
            b.clear();
        }
        return ans.size();
    }
};

int main(){

	return 0;
}
