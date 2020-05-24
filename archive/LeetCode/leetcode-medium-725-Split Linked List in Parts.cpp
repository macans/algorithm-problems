/**
 * @authors: https://github.com/macans
 * @date: 2020-05-24 21:38:26
 * 
 * each part's lengh is len / k, plus 1 more if it locates at the 
 * first mod() = len % k) parts;
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

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode *cur = root;
        while(cur != NULL){
            cur = cur->next;
            ++len;
        }
        
        int n = len / k, mod = len % k;
        cur = root;
        ListNode* last = NULL;
        vector<ListNode*> res;
        while(res.size() != k){
            int j;
            if(res.size() < mod){
                j = n + 1;
            }
            else{
                j = n;
            }
            res.push_back(cur);
            if(cur == NULL) continue;
            j--;
            while(j-- > 0){
                cur = cur->next;
            }
            last = cur->next;
            cur->next = NULL;
            cur = last;
        }
        return res;
    }
};

int main(){

}