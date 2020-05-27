/**
 * @authors: https://github.com/macans
 * @date: 2020-05-27 17:03:14
 * 
 * merge sort
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        
        ListNode* cur = head, *mid = head;
        int i = 0;
        while(cur && cur->next){
            if(i % 2) mid = mid->next;
            cur = cur->next;
            i++;
        }
        
        ListNode *right = sortList(mid->next);
        mid->next = NULL;
        ListNode *left = sortList(head);
        
        //merge
        ListNode* last = NULL;
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                cur = left;
                left = left->next;
            }    
            else{
                cur = right;
                right = right->next;
            }
            if(last == NULL){
                head = cur;
                last = cur;
                continue;
            }
            last->next = cur;
            last = cur;
        }
        if(left != NULL){
           last->next = left;
        }
        if(right != NULL){
            last->next = right;
        }
        
        return head;
    }
};

int main(){

}