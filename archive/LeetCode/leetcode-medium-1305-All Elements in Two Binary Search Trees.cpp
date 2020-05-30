/**
 * @authors: https://github.com/macans
 * @date: 2020-05-30 20:30:40
 * 
 * merge sort
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
    void work(TreeNode* cur, vector<int> &res){
        if(cur == NULL) return;
        work(cur->left, res);
        res.push_back(cur->val);
        work(cur->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2, ans;
        work(root1, res1);
        work(root2, res2);
        int i = 0, j = 0;
        while(i < res1.size() && j < res2.size()){
            if(res1[i] <= res2[j]){
                ans.push_back(res1[i++]);
            }
            else{
                ans.push_back(res2[j++]);
            }
        }
        for(i; i < res1.size(); i++){
            ans.push_back(res1[i]);
        }
        for(j; j < res2.size(); j++){
            ans.push_back(res2[j]);
        }
        return ans;
    }
};

int main(){

}
