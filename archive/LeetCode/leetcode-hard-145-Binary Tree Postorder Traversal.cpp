/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 15:28:21
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        TreeNode* cur = root, *last = nullptr;
        while(true){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if(s.empty()) break;
            cur = s.top();
            if(cur->right && last != cur->right){
                cur = cur->right;
            }
            else{
                ans.push_back(cur->val);
                last = cur;
                s.pop();
                cur = nullptr;
            }
        }
        return ans;
    }
};

int main(){

}
