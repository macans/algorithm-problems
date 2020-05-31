/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 14:33:09
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

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if(!root) return ans;
        TreeNode *cur = root;
        s.push(cur);
        set<TreeNode*> vis;
        vis.insert(nullptr);
        while(!s.empty()){
            cur = s.top(); s.pop();
            if(vis.count(cur->left)){
                ans.push_back(cur->val);
                vis.insert(cur);
                if(cur->right) s.push(cur->right);
            }
            else{
                s.push(cur);
                s.push(cur->left);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if(!root) return ans;
        TreeNode *cur = root;
        while(true){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if(s.empty()) break;
            cur = s.top(); s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};

int main(){

}
