/**
 * @authors: https://github.com/macans
 * @date: 2020-05-30 20:28:38
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
    TreeNode *work(vector<int> &a, int l, int r){
        if(l >= r) return NULL;
        TreeNode *cur = new TreeNode(a[l]);
        auto it = upper_bound(a.begin() + l + 1, a.begin() + r, a[l]);
        //left
        cur->left = work(a, l + 1, distance(a.begin(), it));
        //right
        cur->right = work(a, distance(a.begin(), it), r);
        return cur;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return work(preorder, 0, preorder.size());
    }
};

int main(){

}
