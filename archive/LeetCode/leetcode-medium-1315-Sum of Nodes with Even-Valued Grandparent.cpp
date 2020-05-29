/**
 * @authors: https://github.com/macans
 * @date: 2020-05-29 16:14:19
 * 
 * basic stack operation
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
    int sumEvenGrandparent(TreeNode* root) {
        stack<pair<int, TreeNode*>> s;
        s.push(make_pair(-1, root));
        int res = 0;
        while(!s.empty()){
            
            pair<int, TreeNode*> cur = s.top();
            s.pop();
            
            int f = (cur.first & 1) ^ 1;
            
            if(cur.second->left != NULL){
                res += f * cur.second->left->val;
                if(cur.second->left->left != NULL || cur.second->left->right != NULL){
                    s.push(make_pair(cur.second->val, cur.second->left));
                }
            }
            
            if(cur.second->right != NULL){
                res += f * cur.second->right->val;
                if(cur.second->right->left != NULL || cur.second->right->right != NULL){
                    s.push(make_pair(cur.second->val, cur.second->right));
                }
                
            }
            
        }
        return res;
    }
};

int main(){

}