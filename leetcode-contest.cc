/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-8-19 00:36:05
   *  File : leetcode-884.cc
   * 
   ********************************************/
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        sort(tree.begin(), tree.end());
        int max1 = 0, max2 = 0, cnt = 0, last = -1;
        for(int x : tree){
            if(x != last){
                if(cnt > max1){
                    max2 = max1;
                    max1 = cnt;
                } else if (cnt > max2){
                    max2 = cnt;
                }
            }
            last = x;
        }
        return max1 + max2;
    }
};

int main(){
    Solution s;
    int t[] = {[1,0,3,4,3]};
    vector<int> tt(t, t + 3);
    cout << 1 << endl;
    printf("%d\n", s.totalFruit(tt));
    set<int> ss;
    ss.s
	return 0;
}
