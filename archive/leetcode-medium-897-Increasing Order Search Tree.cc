/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-9-2 10:55:17
   *  File : leetcode-medium-897-Increasing Order Search Tree.cc
   ********************************************/
#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    TreeNode *cur;   
public:
    TreeNode* increasingBST(TreeNode* root) {
        cur = new TreeNode(0);
        TreeNode* ans = cur;
        inOrder(root);
        return ans->right;
    }

    void inOrder(TreeNode* node){
        if(node == NULL) return;
        inOrder(node->left);
        node->left = NULL;
        cur->right = node;
        cur = node;
        inOrder(node->right);
    }

};

int main(){
    Solution s;
    
}
