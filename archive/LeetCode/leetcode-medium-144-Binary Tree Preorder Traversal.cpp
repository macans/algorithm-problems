/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 14:22:23
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        if(cur == nullptr) return ans;
        s.push(cur);
        while(!s.empty()){
            cur = s.top(); s.pop();
            ans.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        return ans;
    }
};

int main(){

}
