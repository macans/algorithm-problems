
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
public:
    TreeNode* root;
    FindElements(TreeNode* root) {
        if(root -> val == -1) {
            root->val = 1;
        }
        if(root->left != NULL){
            root->left->val = root->val << 1;
            FindElements(root->left);
        }
        if(root->right != NULL){
            root->right->val = (root->val << 1) | 1;
            FindElements(root->right);
        }
        this->root = root;
    }
    
    bool find(int target) {
        target += 1;
        int k = 0;
        while(t != 1){
            ++k;
            t >>= 1;
        }
        TreeNode* cur = root;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main(){
    Solution s;
    vector<int> a, b;
    s.findMedianSortedArrays(a, b);
}


