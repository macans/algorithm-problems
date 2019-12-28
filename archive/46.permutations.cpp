/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (53.74%)
 * Total Accepted:    360.2K
 * Total Submissions: 662.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > res;
public:
    void work(int cur, vector<int>& nums){
        if(cur >= nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = cur; i < nums.size(); i++){
            swap(nums[cur], nums[i]);
            work(cur + 1, nums);
            swap(nums[cur], nums[i]);
        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        work(0, nums);
        return res;
    }
};

