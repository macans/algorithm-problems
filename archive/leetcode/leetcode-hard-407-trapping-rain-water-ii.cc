/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-11-25 01:32:35
   *  File : leetcode-hard-407-trapping-rain-water-ii.cc
   ********************************************/
#include <vector>

using namespace std;

class Solution {
private:
        int left[150][150], right[150][150], up[150][150], down[150][150];

public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        if(heightMap.empty()|| heightMap[0].empty()) return 0;
        int m = heightMap[0].size(), n = heightMap.size();
        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i++){
            left[i][0] = 0;
            for(int j = 1; j < m; j++){
                left[i][j] = max(left[i][j - 1], heightMap[i][j - 1]);
            }
            right[i][m - 1] = 0;
            for(int j = m - 2; j >= 0; j--){
                right[i][j] = max(right[i][j + 1], heightMap[i][j + 1]);
            }
        }
        for(int i = 0; i < m; i++){
            up[0][i] = 0;
            for(int j = 0; j < n; j++){
                up[j][i] = max(up[j - 1][i], heightMap[j - 1][i]);
            }
            down[n - 1][i] = 0;
            for(int j = n - 2; j >= 0; j--){
                up[j][i] =max(up[j + 1][i], heightMap[j + 1][i]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += max(
                    min(
                        min(left[i][j], right[i][j]), 
                        min(up[i][j], down[i][j])
                    ), 
                    0);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int> > v;
    s.trapRainWater(v);
	return 0;
}
