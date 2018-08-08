/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-6-25 15:18:52
   *  File : codeforces-980D.cc
   *  去掉每个数的完全平方数因子，对于每个子序列的答案就是序列中不同数字的个数
   ********************************************/
#include <cstdio>
#include <cmath>
#include <cstring>

#define maxn 5005
using namespace std;

int main(){
    int n;
    int a[maxn], ans[maxn];
    int vis[maxn << 1];
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
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            memset(vis, 0, sizeof(vis));
            for(int j = 0; j < i; ++j){
                if(!vis[a[j] + maxn]){
                    ++cnt;
                }
                ++vis[a[j] + maxn];
            }
            ++ans[cnt];
            for(int j = i; j < n; ++j){
                --vis[a[j - i] + maxn];
                if(!vis[a[j - i] + maxn]){
                    --cnt;
                }
                if(!vis[a[j] + maxn]){
                    ++cnt;
                }
                ++vis[a[j] + maxn];                    
                ++ans[cnt];
            }
        }
        for(int i = 1; i <= n; ++i){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
	return 0;
}
