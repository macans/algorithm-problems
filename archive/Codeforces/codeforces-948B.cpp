/******************************************
*  Author : https://github.com/macans   
*  Created On : 2018-04-07
*  File : codeforces-948B.cpp
对于X2, 上一个质数确定以后,X1的区间为[X2-P+1,X2],也就是说质数越大,X1的最小值越小
所以找到X2的最大质因数就可以了
*******************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 1000005;
int maxPrime[maxn];
int erat(){
    bool notPrime[maxn];
    memset(maxPrime, 0, sizeof(maxPrime));
    for(int i = 2; i <= maxn; ++i){
        if(maxPrime[i]) continue;
        for(int j = i * 2; j <= maxn; j += i){
            maxPrime[j] = i;
        }
    }
}
int main(){
    erat();
    int n;
    while(~scanf("%d", &n)){
        int m = n - maxPrime[n] + 1;
        int ans = inf;
        for(int i = m; i <= n; ++i){
            int x = maxPrime[i];
            if(x == i) continue;
            ans = min(i - x + 1, ans);
        }
        printf("%d\n", ans);
    }
}