/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-11-25 00:57:03
   *  File : leetcode-hard-42-trapping-rain-water.cc
   ********************************************/
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int *left= new int[height.size()], *right = new int[height.size()];
        left[0] = 0;
        for(int i = 1; i < height.size(); i++){
            left[i] = max(left[i - 1], height[i - 1]);
        }
        right[height.size() - 1] = 0;
        for(int i = height.size() - 2; i >= 0; i--){
            right[i] = max(right[i + 1], height[i + 1]);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            ans += max(0, min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};
int main(){

	return 0;
}
