/**
 @authors: https://github.com/macans
 @date: 2020-05-16 23:49:43
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
#define pp pair<int, int>
#define MAXN 
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* work(vector<int> &nums, int l, int r){
        if(nums.size() == 0) return NULL;
        int mid = (l + r) >> 1;
        TreeNode* cur = new TreeNode();
        cur->val = nums[mid];
        if(mid > l){
            cur->left = work(nums, l, mid);
        }
        if(mid + 1 < r){
            cur->right = work(nums, mid + 1, r);
        }
        return cur;
    }
    TreeNode*sortedArrayToBST(vector<int>& nums) {
        return work(nums, 0, nums.size());
        
    }
};

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	ios_base::sync_with_stdio(0);
	
}