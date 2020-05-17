/**
 * @authors: https://github.com/macans
 * @date: 2020-05-18 03:14:13
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
#define pp pair<int, int>
#define MAXN 
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *headEven = NULL;
        ListNode *curOdd = head, *curEven = NULL;
        while(curOdd != NULL){
            if(curOdd->next != NULL){
                //Even Node
                if(headEven == NULL){
                    headEven = curOdd->next;
                    curEven = headEven;
                }
                else{
                    curEven->next = curOdd->next;
                    curEven = curEven->next;
                }
                
                if(curOdd->next->next == NULL){
                    curOdd->next = headEven;
                    break;
                } else{
                    curOdd->next = curOdd->next->next;
                    curEven->next = NULL;
                }
            }
            
            if(curOdd->next == NULL){
                curOdd->next = headEven;
                break;
            }
            else{
                curOdd = curOdd->next;
            }
        }
        
        return head;
    }
};

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	ios_base::sync_with_stdio(0);
	
}