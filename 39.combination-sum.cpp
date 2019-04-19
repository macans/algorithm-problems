/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.05%)
 * Total Accepted:    312.8K
 * Total Submissions: 664.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    vector<vector<int> > result;
public:
    void work(int sum, int target, int k, vector<int> ans, vector<int>& candidates){
        if(sum == target){
            result.push_back(ans);
            return;
        }
        for(int i = k; i < candidates.size(); ++i){
            if(sum + candidates[i] > target) break;
            ans.push_back(candidates[i]);
            work(sum + candidates[i], target, i, ans, candidates);
            ans.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        work(0, target, 0, ans, candidates);
        return result;
    }
};

