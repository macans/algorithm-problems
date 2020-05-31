/**
 * @authors: https://github.com/macans
 * @date: 2020-05-30 22:22:45
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
    int traverse(TreeNode* r, int &ans) {
      if (r == NULL) return 0;
      int left = traverse(r->left, ans), right = traverse(r->right, ans);
      ans += abs(left) + abs(right);
      return r->val + left + right - 1;
    }
    
    int distributeCoins(TreeNode* r, int ans = 0) {
        traverse(r, ans);
        return ans;
    }
};

int main(){

}
