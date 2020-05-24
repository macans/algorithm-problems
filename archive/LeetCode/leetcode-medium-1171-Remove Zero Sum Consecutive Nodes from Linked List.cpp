/**
 * @authors: https://github.com/macans
 * @date: 2020-05-25 00:41:33
 * 
 * use map to record the historical sum
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> pos;
        ListNode* cur = head, *temp = NULL;
        int sum = 0;
        pos[0] = NULL;
        while(cur != NULL){
            sum += cur->val;
            if(pos.find(sum) != pos.end()){
                ListNode* last = pos[sum];
                //clear historical sum from last to cur
                temp = last == NULL ? head : last->next;
                int sum1 = sum;
                while(temp != cur){
                    sum1 += temp->val;
                    pos.erase(sum1);
                    temp = temp->next;
                }
                
                if(last == NULL){
                    head = cur->next;
                }
                else{
                    last->next = cur->next;
                }
            }
            else{
                pos[sum] = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main(){

}