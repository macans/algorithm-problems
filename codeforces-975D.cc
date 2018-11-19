/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-5-20 16:01:31
   *  File : codeforces-975D.cc
   ********************************************/
#include <stdio.h>
#include <map>
#include <utility>

const int maxn = 200005;
typedef long long ll;
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    ll a, b;
    scanf("%lld%lld", &a, &b);
    map<ll, ll> vis;
    map<pair<int, int>, int> cnt;
    int x, vx, vy;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &x, &vx, &vy);
        ans += vis[a * vx - vy] - cnt[{vx, vy}];
        vis[a * vx - vy]++;
        cnt[{vx, vy}]++;
    }
    printf("%lld\n", ans << 1);
    return 0;
}