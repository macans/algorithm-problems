/**
 * @authors: https://github.com/macans
 * @date: 2020-04-21 23:50:17
 * codeforces-1332C
 * 回文串
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

string s;
int cnt[26];
int main(){
#ifdef OPEN_FILE
    //freopen("in.txt", "r", stdin);
#endif 
    int T, n, k;
    cin >> T;
    while(T--){
        cin >> n >> k;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < (k + 1) >> 1; i++){
            memset(cnt, 0, sizeof(cnt));
            for(int j = i, p = k - i - 1; j < n || p < n; j += k, p += k){
                //cout << j << " " << p << endl;
                ++cnt[s[j] - 'a'];
                if(j != p){
                    ++cnt[s[p] - 'a'];
                }
            }
            int *max_it = max_element(cnt, cnt + 26);
            //cout << *max_it << endl;
            if((k & 1) && (i == k >> 1)){
                ans += n/k - *max_it;
            }
            else{
                ans += ((n/k) << 1) - *max_it;
            }
        }
        cout << ans << endl;
    }
}