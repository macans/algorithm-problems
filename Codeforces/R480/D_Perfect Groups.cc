/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-6-25 15:18:52
   *  File : codeforces-980D.cc
   *  去掉每个数的完全平方数因子，对于每个子序列的答案就是序列中不同数字的个数
   ********************************************/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
#define maxn 5005
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin);
    int n;
    int a[maxn], ans[maxn], b[maxn];
    while(~scanf("%d", &n)){
        for (int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 2; j <= 10000; ++j){
                if(a[i] % (j * j) == 0){
                    a[i] /= j * j;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            b[i] = a[i];
        }
        sort(b, b + n);
        int m = unique(b, b + n) - b;
        for(int i = 0; i < n; ++i){
            a[i] = lower_bound(b, b + m, a[i]) - b;
        }
        int pos0 = lower_bound(b, b + m, 0) - b;
        if(b[pos0] != 0){
            pos0 = -1;
        }
        memset(ans, 0, sizeof(ans));
       for(int i = 0; i < n; ++i){
           int cnt = 0;
           memset(b, 0, sizeof(b));
           for(int j = i; j < n; ++j){
               if(a[j] != pos0 && b[a[j]] == 0){
                   ++cnt;
               }
               b[a[j]] = 1;
               ++ans[max(cnt, 1)];
           }
       }
        for(int i = 1; i <= n; ++i){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
	return 0;
}
