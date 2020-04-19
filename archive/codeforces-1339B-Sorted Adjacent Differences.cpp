/**
 * @authors: https://github.com/macans
 * @date: 2020-04-19 09:29:21
 */

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
#include <utility>
#define ll long long
#define INF 0x3f3f3f3f
#define OPEN_FILE
#define MAXN 100005
using namespace std;

typedef pair<int, ll> pp;

ll a[MAXN], b[MAXN];

bool compare(pp &a, pp &b){
    return a.second < b.second;
}
int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
#endif 
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            
        }
        sort(a, a + n);
        int l = 1, r = n - 1;
        memset(b, 0, sizeof(b));
        int cnt = 0;
        b[0] = a[0];
        while(l <= r){
            if(abs(a[l] - b[cnt]) >= abs(a[r] - b[cnt])){
                b[++cnt] = a[l++];
            }
            else{
                b[++cnt] = a[r--];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            printf("%lld ", b[i]);
        }
        printf("\n");
    }
}