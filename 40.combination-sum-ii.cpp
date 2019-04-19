/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.44%)
 * Total Accepted:    210.3K
 * Total Submissions: 515.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include <vector>
#include <map>
#include <utility>
using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    map<int, int> cnt;
    int record;
public:
    void work(int sum, int target, int k, vector<pair<int, int> > ans, vector<int>& candidates, vector<int>& cnt){
        //printf("%d %d %d %ld\n", sum, target, k, ans.size());
        if(sum == target){
            vector<int> tmp;
            for(int i = 0; i < ans.size(); i++){
                for(int j = 0; j < ans[i].second; j++){
                    tmp.push_back(ans[i].first);
                }
            }
            result.push_back(tmp);
            return;
        }
        if(k == candidates.size()) return;
        for(int i = 0; i <= cnt[k]; i++){
            if (sum + i * candidates[k] > target) continue;
            ans.push_back(make_pair(candidates[k], i));
            work(sum + i * candidates[k], target, k + 1, ans, candidates, cnt);
            ans.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        record = 0;
        vector<int> a, b;
        for(int i = 0; i < candidates.size();){
            a.push_back(candidates[i]);
            int j = 1;
            while(++i < candidates.size() && candidates[i] == candidates[i - 1]){
                j++;
            }
            b.push_back(j);
        }
        for(int i = 0; i < a.size(); ++i){
            printf("%d - %d\n", a[i], b[i]);
        }
        printf("\n");
        vector<pair<int, int> > ans;
        work(0, target, 0, ans, a, b);
        return result;
    }
};

// int main(){
//     Solution s;
//     vector<int> candidates = {2,5,2,1,2};
//     s.combinationSum2(candidates, 5);
// }