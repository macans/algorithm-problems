/**
 * @authors: https://github.com/macans
 * @date: 2020-05-30 22:11:50
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
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        stack<pair<int, TreeNode*>> s;
        s.push(make_pair(root->val, root));
        while(!s.empty()){
            pair<int, TreeNode*> cur = s.top();
            s.pop();
            if(cur.first <= cur.second->val){
                ++ans;
            }
            if(cur.second->left != NULL){
                s.push(make_pair(max(cur.first, cur.second->left->val), cur.second->left));
            }
            if(cur.second->right != NULL){
                s.push(make_pair(max(cur.first, cur.second->right->val), cur.second->right));
            }
        }
        return ans;
    }
};

int main(){

}
