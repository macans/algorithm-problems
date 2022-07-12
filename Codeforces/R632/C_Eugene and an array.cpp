/**
 * @authors: https://github.com/macans
 * @date: 2020-04-19 23:09:35
 * 思维 前缀和
 * codeforces-1333C
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

ll sum[MAXN];
set<ll> s;

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
#endif 
    int n;
    ll x;
    scanf("%d", &n);
    sum[0] = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &x);
        sum[i + 1] = sum[i] + x;
    }
    int l = 0, r = 0;
    ll ans = 0;
    int cnt = 0;
    while(l < n){
        s.insert(sum[l]);
        while(r < n && s.find(sum[r + 1]) == s.end()){
            s.insert(sum[++r]);
        }
        ans += r - l;
        s.erase(sum[l++]);
        r = max(r, l);
    }
    printf("%lld\n", ans);
}