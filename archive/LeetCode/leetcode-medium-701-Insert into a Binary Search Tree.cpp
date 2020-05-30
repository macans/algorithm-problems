/**
 * @authors: https://github.com/macans
 * @date: 2020-05-30 20:21:03
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *cur = root, *last = NULL;
        while(cur != NULL){
            last = cur;
            if(val > cur->val){
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
        if(last == NULL){
            return new TreeNode(val);
        }
        if(val > last->val){
            last->right = new TreeNode(val);
        }
        else{
            last->left = new TreeNode(val);
        }
        return root;
    }
};

int main(){

}
