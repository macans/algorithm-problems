/******************************************
*  Author : https://github.com/macans   
*  Created On : 2018-05-08
*  File : codeforces-975C.cpp
*******************************************/
#include <cstring>
#include <cstdio>
#include <algorithm>

const int maxn = 200005;
using namespace std;

int main(){
    int n, m;
    long long a[maxn], b[maxn], sum[maxn];
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    scanf("%d %d", &n, &m);
    scanf("%I64d", &a[0]);
    sum[0] = a[0];
    for(int i = 1; i < n; i++){
        scanf("%I64d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    long long x = 0, y = 0;
    for(int i = 0; i < m; i++){
        scanf("%I64d", &x);
        y += x;
        int ans = n - (upper_bound(sum, sum + n, y) - sum);
        if(ans == 0){
            y = 0;
            ans = n;
        }
        printf("%d\n", ans);
    }
}