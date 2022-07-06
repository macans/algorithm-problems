/**
 * codeforces-1339C
 * 
 * @authors: https://github.com/macans
 * @date: 2020-04-19 21:20:07
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
#define pp pair<int, int>
#define MAXN 100005
using namespace std;

int a[MAXN], temp[MAXN];
int max_inversion;

void merge_sort(int l, int r, int* a, int* temp){
    if(r - l == 1) {
        return;
    }

    int mid = (l + r) >> 1;
    //printf("%d %d %d\n", l, r, mid);
    merge_sort(l, mid, a, temp);
    merge_sort(mid, r, a, temp);
    max_inversion = max(max_inversion, a[mid - 1] - a[mid]);
    
    int p = l, q = mid, k = l;
    while(p < mid && q < r){
        //printf("%d %d %d %d %d %d\n", l, r, p, q, a[p], a[q]);
        if(a[p] <= a[q]){
            temp[k++] = a[p++];
        }
        else{
            temp[k++] = a[q++];
        }
    }
    //printf("p=%d q=%d k=%d\n", p, q, k);
    for(int i = p; i < mid; i++){
        temp[k++] = a[i];
    }
    for(int i = q; i < r; i++){
        temp[k++] = a[i];
    }
    for(int i = l; i < r; i++){
        a[i] = temp[i];
    }
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
           scanf("%d", &a[i]);
       }
       max_inversion = 0;
       merge_sort(0, n, a, temp);
       //printf("%d\n", max_inversion);
       int ans = 0;
       while(max_inversion > 0){
           max_inversion -= 1 << (ans++);
       }
       printf("%d\n", ans);
   } 
}