/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 21:52:00
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
    int ans;
    //0 -> is not monitored, 1 -> monitored, no camera, 2 -> is camera
    int work(TreeNode* cur){
        if(!cur) return 1;
        int l = work(cur->left);
        int r = work(cur->right);
        if(l == 0 || r == 0) {
            ++ans;
            return 2;
        }
        if(l == 2 || r == 2){
            return 1;
        }
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        ans = 0;
        if(!root) return 0;
        if(!work(root)) ++ans;
        return ans;
    }
};

int main(){

}
