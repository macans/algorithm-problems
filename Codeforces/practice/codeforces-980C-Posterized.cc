/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-5-20 16:01:31
   *  File : codeforces-980C.cc
   * 
   * Choose largest left element at each operation
   ********************************************/
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstring>

const int maxn = 100005;
typedef long long ll;
using namespace std;

int main(){
    int n, k, x;
    int key[maxn];
    while(~scanf("%d%d", &n, &k)){
        for(int i = 0; i < 256; i++){
            key[i] = -1;
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            if(key[x] == -1){
                for(int j = max(0, x - k + 1); j <= x; j++){
                    if(key[j] == -1 || key[j] == j){
                        for(int p = j; p <= x; ++p){
                            key[p] = j;
                        }
                        break;
                    }
                }
            }
            printf("%d ", key[x]);
        }
        printf("\n");
    }
}