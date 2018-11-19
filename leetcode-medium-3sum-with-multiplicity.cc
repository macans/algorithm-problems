/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-10-17 22:02:35
   *  File : leetcode-medium-3sum-with-multiplicity.cc
   ********************************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <unistd.h>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int mod = 1000000007;
        int ans = 0;
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); ++i){
            if(A[i] > target) continue;
            int t = target - A[i];
            int left = i + 1, right = A.size() - 1;
            while(left < right){
                if(A[left] + A[right] < t){
                    ++left;
                }
                else if(A[left] + A[right] > t){
                    --right;
                }
                else if(A[left] == A[right]){
                    ans = (ans + (right - left) * (right - left + 1) / 2) % mod;
                    break;
                }
                else{
                    int left_cnt = 1, right_cnt = 1;
                    while(left + 1 < right && A[left + 1] == A[left]){
                        ++left;
                        ++left_cnt;
                    }
                    while(right - 1 > left && A[right - 1] == A[right]){
                        --right;
                        ++right_cnt;
                    }
                    ans = (ans + left_cnt * right_cnt) % mod;
                    ++left;
                    --right;
                }
            }
        }
        return ans;
    }
};

int main(){

    Solution s;
    int b[10] = {1,1,2,2,2,2};
    vector<int> a;
    a.insert(a.begin(), b, b + 6);
    cout << s.threeSumMulti(a, 5) << endl;
	return 0;
}
