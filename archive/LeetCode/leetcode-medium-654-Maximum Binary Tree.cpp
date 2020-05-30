/**
 * @authors: https://github.com/macans
 * @date: 2020-05-29 21:19:15
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        map<int, TreeNode*> s;
        for(int i = 0; i < nums.size(); i++){
            auto it = s.insert(make_pair(nums[i], new TreeNode(nums[i]))).first;
            if(it != s.begin()){
                it->second->left = next(it, -1)->second;
                s.erase(s.begin(), it);
            }
            if(next(it, 1) != s.end()) {
                next(it, 1)->second->right = it->second;
            }
        }
        return s.rbegin()->second;
    }
};

class Solution2 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<pair<int, TreeNode*> > s;
        s.push_back(make_pair(nums[0], new TreeNode(nums[0])));
        for(int i = 1; i < nums.size(); i++){
            TreeNode* cur = new TreeNode(nums[i]);
            pair<int, TreeNode*> p = make_pair(nums[i], cur);
            auto it = lower_bound(s.rbegin(), s.rend(), p); 
            if(it != s.rend()){
                it->second->right = cur;
            }
            if(it != s.rbegin()){
                cur->left = next(it, -1)->second;
            }
            s.resize(distance(it, s.rend()));
            s.push_back(p);
        }
        return s.front().second;
    }
};

int main(){
}
