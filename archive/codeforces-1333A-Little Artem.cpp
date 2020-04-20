/**
 * @authors: https://github.com/macans
 * @date: 2020-04-19 22:42:30
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
#define MAXN 
using namespace std;

int main(){
#ifdef OPEN_FILE
    freopen("in.txt", "r", stdin);
#endif 
    int T;
    int n, m;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        printf("W");
        for(int i = 1; i < m; i++){
            printf("B");
        }
        printf("\n");
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("B");
            }
            printf("\n");
        }
    }
}