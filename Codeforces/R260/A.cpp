/**
 * <http://codeforces.com/problemset/problem/455/A>
 * DP
 * 
 * @macinchang
 * Created on  2021-06-21 18:33:42 
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstring>

const int maxn = 100005;
typedef long long ll;
using namespace std;

int main() {
    ll cnt[maxn], f[maxn][2];
    int n, x;
    while(~scanf("%d", &n)){
        memset(f, 0, sizeof(f));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            ++cnt[x];
        }
        f[1][0] = 0;
        f[1][1] = cnt[1];
        ll ans = max(f[1][0], f[1][1]);
        for(int i = 2; i <= 100000; i++){
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = max(f[i - 1][0] + cnt[i] * i, f[i - 1][1]);
            ans = max(ans, max(f[i][0], f[i][1]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
