/**
 * @authors: https://github.com/macans
 * @date: 2020-04-19 00:40:53
 * 二分
 * 
 * codeforces-1337D
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
#define INF 0x3f3f3f3f3f3f3f3fLL
#define OPEN_FILE
#define MAXN 100005
using namespace std;

typedef pair<char, ll> pp;

ll color[3][MAXN];
int last[305];

ll find_smaller(ll *begin, ll *end, ll x){
    ll *it = lower_bound(begin, end, x);
    if(it == begin || (it != end && *it == x)) return *it;
    return *(it - 1);
}

ll find_bigger(ll *begin, ll *end, ll x){
    ll *it = lower_bound(begin, end, x);
    if(it == end) return *(it - 1);
    return *it;
}

ll calc(ll &x, ll &y, ll &z){
    ll a = x - y, b = y - z, c = x - z;
    return a * a + b * b + c * c;
}

int main(){
#ifdef OPEN_FILE
    //freopen("in.txt", "r", stdin);
#endif 

    int T;
    cin >> T;
    int nr, ng, nb, n;
    while(T--){
        cin >> color[0][0] >> color[1][0] >> color[2][0];
        for(int i = 1; i <= color[0][0]; i++){
            cin >> color[0][i];
        }
        for(int i = 1; i <= color[1][0]; i++){
            cin >> color[1][i];
        }
        for(int i = 1; i <= color[2][0]; i++){
            cin >> color[2][i];
        }
        for(int i = 0; i < 3; i++){
            sort(color[i] + 1, color[i] + color[i][0] + 1);
            // for(int j = 1; j <= color[i][0]; j++){
            //     cout << color[i][j] << " " ;
            // }
            // cout << endl;
        }
      
        ll ans = INF;
        for(int i = 0; i < 3; i++){
            for(int j = 1; j <= color[i][0]; j++){
                int p = (i + 1) % 3, q = (i + 2) % 3;
                //b r g
                ll x = find_smaller(color[p] + 1, color[p] + color[p][0] + 1, color[i][j]);
                ll z = find_bigger(color[q] + 1, color[q] + color[q][0] + 1, color[i][j]);
                //cout << x << " " << color[i][j] << " " << z << endl;
                ans = min(ans, calc(x, color[i][j], z));
                //g r b
                x = find_smaller(color[q] + 1, color[q] + color[q][0] + 1, color[i][j]);
                z = find_bigger(color[p] + 1, color[p] + color[p][0] + 1, color[i][j]);
                //cout << x << " " << color[i][j] << " " << z << endl;
                ans = min(ans, calc(x, color[i][j], z));
                //cout << endl;
            }
        }
        printf("%lld\n", ans);
    }
}