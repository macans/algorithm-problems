/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-12-15 18:52:32
   *  File : leetcode-medium-.cc
   ********************************************/
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i > res) return false;
            if(nums[i] + i > res){
                res = nums[i] + i;
            }
            if(res >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main(){

	return 0;
}
