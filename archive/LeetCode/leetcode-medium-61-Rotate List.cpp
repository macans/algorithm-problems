/**
 * @authors: https://github.com/macans
 * @date: 2020-05-14 22:21:18
 * 
 * 
 */

#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define OPEN_FILE
#define pp pair<int, int>
#define MAXN 
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *cur = head;
        int len = 1;
        while(cur->next != NULL){
            cur = cur->next;
            ++len;
        }
        cur->next = head;
        cur = head;
        k = len - (k % len) - 1;
        while(k--){
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	
}