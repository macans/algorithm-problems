/******************************************
*  Author : https://github.com/macans   
*  Created On : 2018-04-07
*  File : codeforces-948C.cpp

left[i]表示第i天结束后还剩多少堆
sum[i]表示第i天消失的雪堆的总体积
*******************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll int64_t
#define maxn 100005
using namespace std;

ll left[maxn], sum[maxn];
ll a[maxn], b[maxn];

int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i <= n; ++i){
            left[i] = 1;
        }
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; ++i){
            scanf("%I64d", &a[i]);
        }
        for(int i = 0; i < n; ++i){
            scanf("%I64d", &b[i]);
        }
        for(int i = 1; i < n; ++i){
            b[i] += b[i - 1];
        }
        for(int i = 0; i < n; ++i){
            int x;
            if(i == 0){
                x = lower_bound(b, b + n, a[i]) - b;
            } else {
                x = lower_bound(b, b + n, a[i] + b[i - 1]) - b;
            }
            x = max(i, x);
            --left[x];
            if(x > 0){
                sum[x] += (a[i] + b[i - 1]) - b[x - 1];
            }
            else{
                sum[x] += a[i];
            }
        }
        for(int i = 1; i < n; ++i){
            left[i] += left[i - 1];
        }
        printf("%I64d ", left[0] * b[0] + sum[0]);
        for(int i = 1; i < n; ++i){
            printf("%I64d ", left[i] * (b[i] - b[i - 1]) + sum[i]);
        }
    }
}
