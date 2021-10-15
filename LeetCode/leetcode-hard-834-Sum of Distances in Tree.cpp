/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 16:54:28
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;

    }

    void dfs(int cur, int father) {
        for (auto i : tree[cur]) {
            if (i == father) continue;
            dfs(i, cur);
            count[cur] += count[i];
            res[cur] += res[i] + count[i];
        }
    }

    void dfs2(int cur, int father) {
        for (auto i : tree[cur]) {
            if (i == father) continue;
            res[i] = res[cur] - count[i] + count.size() - count[i];
            dfs2(i, cur);
        }
    }
};

int main(){

}
