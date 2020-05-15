/**
 * @authors: https://github.com/macans
 * @date: 2020-05-15 23:38:12
 * 
 * Merge all lists into one, let a window move forward step by step.
 */

#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define OPEN_FILE
#define pp pair<int, int>
#define MAXN 
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> a;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                a.push_back(make_pair(nums[i][j], i));
            }
        }
        int n = a.size(), k = nums.size();
        sort(a.begin(), a.end());
        
        int l = 0, r = 0;
        int ans = 1e6, ansl, ansr;
        int cnt[3505], cur = 0;
        memset(cnt, 0, sizeof(cnt));
        while(l < n){
            while(cur != k && r < n){
                if(cnt[a[r].second] == 0){
                    ++cur;
                }
                ++cnt[a[r].second];
                if(cur == k) break;
                ++r;
            }
            if(r == n) break;
            //move right
            while(cur == k){
                if(a[r].first - a[l].first < ans){
                    ans = a[r].first - a[l].first;
                    ansl = a[l].first;
                    ansr = a[r].first;
                }
                cnt[a[l].second]--;
                if(cnt[a[l].second] == 0){
                    --cur;
                }
                ++l;
            }
            ++r;
        }
        vector<int> res;
        res.push_back(ansl);
        res.push_back(ansr);
        return res;
    }
};

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	
}