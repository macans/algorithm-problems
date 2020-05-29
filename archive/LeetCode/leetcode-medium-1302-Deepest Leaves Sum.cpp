/**
 * @authors: https://github.com/macans
 * @date: 2020-05-29 15:38:27
 * 
 * stack or queue will be ok
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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 0));
        int res = 0, depth = 0, max_depth = 0;
        while(!s.empty()){
            pair<TreeNode*,int> cur = s.top();
            
            s.pop();
            
            //leaf 
            if(cur.first->left == NULL && cur.first->right == NULL){
                if(cur.second < max_depth) continue;
                if(cur.second == max_depth){
                    res += cur.first->val;
                }
                else {
                    max_depth = cur.second;
                    res = cur.first->val;
                }
                continue;
            }
            
            if(cur.first->left != NULL){
                s.push(make_pair(cur.first->left, cur.second + 1));
            }
            if(cur.first->right != NULL){
                s.push(make_pair(cur.first->right, cur.second + 1));
            }
        }
        return res;
    }
};

int main(){

}