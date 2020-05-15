
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
#define ll long long
#define INF 0x3f3f3f3f
#define OPEN_FILE

using namespace std;

int main(){
#ifdef OPEN_FILE
    //freopen("in.txt", "r", stdin);
#endif
    int m, n, p, k;
    int a[200005];
    while(~scanf("%d", &m)){
        while(m--){
            scanf("%d%d%d", &n, &p, &k);
            for(int i = 0; i < n; i++){
                scanf("%d", &a[i]);
            }
            sort(a, a + n);
            int sum = 0, ans = 0, tnt = 0;
            for(int i = 0; i < k; i++){
                sum = tnt;
                int cnt = i;
                for(int j = i + k - 1; j < n; j += k){
                    if(sum + a[j] > p) break;
                    sum += a[j];
                    cnt += k;
                }
                //printf("i=%d, sum=%d, tnt=%d, cnt=%d\n", i, sum, tnt, cnt);
                if(tnt > p) break;
                ans = max(ans, cnt);
                tnt += a[i];
            }
            printf("%d\n", ans);
        }
    }
}

