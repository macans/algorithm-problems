/**
 * @authors: https://github.com/macans
 * @date: 2020-04-19 22:56:38
 * codeforces-1333B
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
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define OPEN_FILE
#define pp pair<int, int>
#define MAXN 100005
using namespace std;

int a[MAXN], b[MAXN];
int main(){
#ifdef OPEN_FILE
    //freopen("in.txt", "r", stdin);
#endif 
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int pos = INF, neg = INF;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            if(a[i] == 1 && pos == INF){
                pos = i;
            }
            if(a[i] == -1 && neg == INF){
                neg = i;
            }
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &b[i]);
        }
        //printf("%d %d\n", pos, neg);
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]) continue;
            if(b[i] > a[i] && pos < i) continue;
            if(b[i] < a[i] && neg < i) continue;
            flag = true;
        }
        if(flag){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}