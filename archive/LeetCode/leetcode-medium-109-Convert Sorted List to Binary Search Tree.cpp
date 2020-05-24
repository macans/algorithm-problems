/**
 * @authors: https://github.com/macans
 * @date: 2020-05-25 00:22:39
 * 
 * choose middle element as root node
 */
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* work(ListNode* left, ListNode* right){
        if(left == right){
            return NULL;
        }
        if(left->next == right){
            return new TreeNode(left->val);
        }
        ListNode *p = left, *q = left;
        while(q != right && q->next != right){
            p = p->next;
            q = q->next->next;
        }
        //cout << p->val << "\n";
        TreeNode* cur = new TreeNode(p->val);
        cur->left = work(left, p);
        cur->right = work(p->next, right);
        return cur;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return work(head, NULL);
    }
};
int main(){

}