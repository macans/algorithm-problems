/**
 * @authors: https://github.com/macans
 * @date: 2020-04-25 23:38:07
 * codeforces-1326C
 * 排列组合，置换
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
#define pp pair<int, ll>
#define MAXN 200005
#define MOD 998244353L
using namespace std;

ll a[MAXN];
pp b[MAXN];
bool vis[MAXN];

bool compare(pp &x, pp &y){
    return x.second > y.second;
}
int main(){
#ifdef OPEN_FILE
    //freopen("in.txt", "r", stdin);
#endif 
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i].first = i;
        b[i].second = a[i];
    }
    sort(b, b + n, compare);
    ll ans = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < k; i++){
        ans += b[i].second;
        vis[b[i].first] = true;
        //cout << ans << " " << b[i].first << endl;
    }
    ll cnt = 0;
    int i = 0;
    while(i < n){
        int k = 1;
        while(i < n && !vis[i]){
            ++i;
            ++k;
        }
        if(!vis[i]) break;
        if(cnt == 0){
            cnt = 1L;
        }
        else{
            cnt = (cnt * k) % MOD;
        }
        //cout << i << " " << cnt << endl;
        i++;
    }
    cout << ans << " " << cnt << endl;
}