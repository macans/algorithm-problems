/**
 * @authors: https://github.com/macans
 * @date: 2020-05-18 02:16:58
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
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s;
        for(int i = 0; i < G.size(); i++){
            s.insert(G[i]);
        }
        ListNode* cur = head;
        int ans = 0;
        bool connected = false;
        while(cur != NULL){
            if(s.find(cur->val) != s.end()){
                if(!connected){
                    ++ans;
                    connected = true;
                }
                cur = cur->next;
                continue;
            }
            connected = false;
            cur = cur->next;
        }
        return ans;
    }
};

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	ios_base::sync_with_stdio(0);
	
}