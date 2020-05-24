/**
 * @authors: https://github.com/macans
 * @date: 2020-05-24 21:26:05
 * 
 * use stack to store next node who has child
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        
        Node* cur = head, *last = NULL;
        while(cur != NULL){
            if(cur->child != NULL){
                if(cur->next != NULL) {
                    s.push(cur->next);
                }
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = NULL;
            }
            
            if(cur->next == NULL && !s.empty()){
                cur->next = s.top();
                cur->next->prev = cur;
                s.pop();
            }
            
            cur = cur->next;
        }
        
        return head;
    }
};
int main(){
	return 0;
}