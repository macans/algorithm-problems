/**
 * @authors: https://github.com/macans
 * @date: 2020-05-16 00:57:55
 * 
 * Pre-process the string as a list of pair (depth, value)
 * 1-2--3---4--5 will be [(0, 1), (1, 2), (2, 3), (3, 4), (2, 5)]
 * Then do the recursion on the pair list, let the return value of 
 * function be the next processing position
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    vector<pair<int, int>> a;
public:
    int work(int depth, int pos, TreeNode *cur){
        //printf("depth=%d, pos=%d\n", depth, pos);        
        cur->val = a[pos].second;
        if(pos == a.size() - 1) return -1;
        
        int pos_new = pos + 1;
        
        if(a[pos_new].first > depth){
            //left node
            cur->left = new TreeNode();
            pos_new = work(depth + 1, pos_new, cur->left);
        }
        if(pos_new != -1 && a[pos_new].first > depth){
            //right node
            cur->right = new TreeNode();
            pos_new = work(depth + 1, pos_new, cur->right);
        }
        return pos_new;
        
    }
    
    TreeNode* recoverFromPreorder(string s) {
        a.clear();
        int i = 0;
        while(i < s.length()){
            int depth = 0, val = 0;
            while(s[i] == '-'){
                ++i;
                ++depth;
            }
            while(i < s.length() && s[i] != '-'){
                val = val * 10 + s[i] - '0';
                ++i;
            }
            a.push_back(make_pair(depth, val));
            //printf("%d, %d\n", depth, val);
        }
        TreeNode *root = new TreeNode();
        work(0, 0, root);
        return root;
    }
};

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	
}