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

using namespace std;

int main(){
#ifdef OPEN_FILE
   //freopen("in.txt", "r", stdin);
#endif 
    int T;
    scanf("%d", &T);
    while(T--){
        int a, n, m;
        scanf("%d%d%d", &a, &n, &m);
        int cnt_n = 0, cnt_m = 0;
        while(a > 20 && n--){
            a = (a >> 1) + 10;
        }
        while(m--){
            a -= 10;
        }
        if(a <= 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}

