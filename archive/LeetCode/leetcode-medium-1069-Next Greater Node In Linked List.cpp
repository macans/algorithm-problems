/**
 * @authors: https://github.com/macans
 * @date: 2020-05-18 02:44:06
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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* cur = head;
        int len = 0;
        while(cur != NULL){
            ++len;
            cur = cur->next;
        }
        
        vector<int> res(len, 0);
        
        stack<pair<int, int>> s;
        
        cur = head;
        int i = 0;
        while(cur != NULL){
            while(!s.empty() && s.top().first < cur->val){
                res[s.top().second] = cur->val;
                s.pop();
            }
            s.push(make_pair(cur->val, i++));
            cur = cur->next;
        }
        return res;
    }
};

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	ios_base::sync_with_stdio(0);
	
}