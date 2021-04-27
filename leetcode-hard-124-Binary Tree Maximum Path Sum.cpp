/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 22:09:02
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
    long long ans;
    long long work(TreeNode* cur){
        if(!cur) return 0LL;
        long long l = work(cur->left), r = work(cur->right);
        ans = max(ans, max(l, 0LL) + max(r, 0LL) + cur->val);
        return max(max(l, r), 0LL) + cur->val;
        
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        work(root);
        return ans;
    }
};

int main(){

}
