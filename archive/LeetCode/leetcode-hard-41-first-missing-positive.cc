/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-11-24 23:04:21
   *  File : leetcode-hard-first-missing-positive.cc
   ********************************************/
#include <vector>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 1 || nums[i] > nums.size()) continue;
            while(nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
int main(){

	return 0;
}
