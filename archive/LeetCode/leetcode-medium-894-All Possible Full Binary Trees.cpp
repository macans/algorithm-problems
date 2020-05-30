/**
 * @authors: https://github.com/macans
 * @date: 2020-05-30 21:21:03
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
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
    unordered_map<int, vector<TreeNode*>> f;
public:
 vector<TreeNode*> allPossibleFBT(int n) {
        if(f.find(n) != f.end()){
            return f[n];
        }
        vector<TreeNode*> res;
        if(n % 2 == 0) return res;
        if(n == 1) {
            res.push_back(new TreeNode(0));
        } else {
            for(int i = 1; i < n; i += 2){
                int l = i, r = n - i - 1;
                for (TreeNode* left : allPossibleFBT(l)) {
                    for (TreeNode* right : allPossibleFBT(r)) {
                        TreeNode * root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        res.push_back(root);
                    }
                }
            }
        }
        f[n] = res;
        return res;
    }
};

int main(){

}
