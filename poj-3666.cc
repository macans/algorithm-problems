/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-8-20 22:35:36
   *  File : poj-3666.cc
   *  dp[i][j] = min(dp[i][k]) + abs(h[i] - j)
   ********************************************/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

#define maxn 2005
#define INF 0x3f3f3f3f3f
typedef long long ll;
using namespace std;

inline ll labs(ll a){
    return a > 0 ? a : -a;
}
ll h[maxn], b[maxn];
ll f[maxn][maxn];

int main(){
    int n;
    //freopen("in.txt", "r", stdin);
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++i){
            scanf("%lld", &h[i]);
            b[i] = h[i];
        }
        sort(b, b + n);
        int m = unique(b, b + n) - b;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; ++j){
                f[i][j] = INF;
            }
        }
        for(int i = 0; i < m; i++){
            f[0][i] = labs(h[0] - b[i]);
        }
        for(int i = 1; i < n; i++){
            ll cur = INF;
            for(int j = 0; j < m; j++){
                cur = min(f[i - 1][j], cur);
                f[i][j] = labs(h[i] - b[j]) + cur;
                //printf("%d %d %d\n", i, b[j], f[i][j]);
            }
        }
        ll ans = INF;
        for(int i = 0; i < m; i++){
            ans = min(ans, f[n - 1][i]);
        }
        printf("%lld\n", ans);
    }
	return 0;
}