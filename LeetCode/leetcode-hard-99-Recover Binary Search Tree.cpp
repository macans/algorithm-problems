/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 14:08:50
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <iostream>
#include <sstream>
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
    TreeNode *p1, *p2;
    TreeNode* last;
    
    void work(TreeNode* cur){
        if(cur->left){
            work(cur->left);
        }
        
        if(!p1 && last->val > cur->val){
            p1 = last;
        }
        if(p1 && last->val > cur->val){
            p2 = cur;
        }
        
        last = cur;
        
        if(cur->right){
            work(cur->right);
        }
    }
    
    void recoverTree(TreeNode* root) {
        if(!root) return;
        last = new TreeNode(INT_MIN);
        p1 = p2 = nullptr;
        work(root);
        swap(p1->val, p2->val);
    }
};
int main(){
	string s = "1 2 3 4";
	istringstream input(s);
	string val;
	input >> val;
	cout << val << "\n";
	cout << stoi(val) << "\n";
}
