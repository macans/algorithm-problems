/**
 * @authors: https://github.com/macans
 * @date: 2020-04-22 01:10:22
 * codeforces-1325C
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
#define MAXN 200005
using namespace std;

vector<int> edge[MAXN];
pp input[MAXN];
bool vis[MAXN];

int main(){
#ifdef OPEN_FILE
    //freopen("in.txt", "r", stdin);
#endif 
    int n, x, y;
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n - 1; i++){
        cin >> input[i].first >> input[i].second;
        edge[input[i].first].push_back(input[i].second);
        edge[input[i].second].push_back(input[i].first);
    }
    int p = 0, q = 0;
    
    
    for(int i = 1; i <= n; i++){
        if(edge[i].size() > 2 && q == 0){
            vis[i] = true;
            //cout << i << "degree >= 3" << endl;
            q = 3;
            for(int j = 0; j < 3; j++){
                vis[edge[i][j]] = true;
            }
        }
    }
    //cout << p << " " << q << endl;
    for(int i = 0; i < n - 1; i++){
        if(vis[input[i].first] && vis[input[i].second]){
            cout << p++ << endl;
        }
        else{
            cout << q++ << endl;
        }
    }

}