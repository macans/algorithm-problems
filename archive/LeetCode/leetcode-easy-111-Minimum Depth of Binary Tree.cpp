/**
 @authors: https://github.com/macans
 @date: 2020-05-16 23:35:44
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNoderoot) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int left = 0x3f3f3f3f, right = 0x3f3f3f3f;
        if(root->left != NULL){
            left = minDepth(root->left) + 1;
        }
        if(root->right != NULL){
            right = minDepth(root->right) + 1;
        }
        return min(left, right);
    }
};

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	ios_base::sync_with_stdio(0);
	
}