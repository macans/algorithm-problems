
/*
codeforces-1337C
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
#define OPEN_FILE
#define MAXN 200005

using namespace std;

struct Node{
    int id;
    int son_cnt;
    int depth;
};

vector<int> edge[MAXN];
Node node[MAXN];
bool industry[MAXN], vis[MAXN];
ll ans;

void calc_node(int x, int depth){
    vis[x] = true;
    node[x].depth = depth;
    if(edge[x].size() == 0){
        node[x].son_cnt = 0;
        return;
    }
    for(int i = 0; i < edge[x].size(); i++){
        if(vis[edge[x][i]]) continue;
        calc_node(edge[x][i], depth + 1);
        node[x].son_cnt += node[edge[x][i]].son_cnt + 1;
    }
}

bool compare_node(Node &a, Node &b){
    return a.son_cnt - a.depth > b.son_cnt - b.depth;
}

void calc_ans(int x, int cnt){
    vis[x] = true;
    if(industry[x]){
        ans += cnt;
    }
    else{
        cnt++;
    }
    for(int i = 0; i < edge[x].size(); i++){
        if(vis[edge[x][i]]) continue;
        calc_ans(edge[x][i], cnt);
    }
}
int main(){
#ifdef OPEN_FILE
   freopen("in.txt", "r", stdin);
#endif 
   int n, k, x, y;
   scanf("%d%d", &n, &k);
   for(int i = 1; i <= n; i++){
       node[i].id = i;
   }

   for(int i = 0; i < n - 1; i++){
       scanf("%d%d", &x, &y);
       edge[x].push_back(y);
       edge[y].push_back(x);
   }
   memset(vis, 0, sizeof(vis));
   calc_node(1, 1);
   sort(node + 1, node + n + 1, compare_node);
   for(int i = 1; i <= n; i++){
       printf("%d %d %d\n", i, node[i].son_cnt, node[i].depth);
   }
   ans = 0;
   for(int i = 1; i <= n - k; i++){
       ans += node[i].son_cnt - node[i].depth;
   }
   printf("%lld\n", ans);
}

