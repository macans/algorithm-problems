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

bool compare(pair<ll, ll> &a, pair<ll, ll> &b){
    return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

int main(){
#ifdef OPEN_FILE
   //freopen("in.txt", "r", stdin);
#endif
    ll cnt_case;
    ll n, T, a, b;
    pair<ll, ll> t[200005];
    scanf("%lld", &cnt_case);
    while(cnt_case--){
        scanf("%lld%lld%lld%lld", &n, &T, &a, &b);
        ll cnt_hard = 0, cnt_easy = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", &t[i].second);
            if(t[i].second == 1) ++cnt_hard;
            else ++cnt_easy;
        }
        for(int i = 0; i < n; i++){
            scanf("%lld", &t[i].first);
        }
        if(cnt_easy * a + cnt_hard * b <= T){
            printf("%lld\n", n);
            continue;
        }
        sort(t, t + n, compare);
        ll ans = 0, cur_hard = 0, cur_easy = 0, required_time = 0, required_points = 0;
        for(int i = 0; i < n; i++){
            int target = t[i].first - 1;
            if(target >= required_time){
                int points = min((target - required_time) / a, cnt_easy - cur_easy);
                points += min((target - required_time - a * points) / b, cnt_hard - cur_hard);
                ans = max(required_points + points, ans);
            }
            if(t[i].second == 1) ++cur_hard;
            else ++cur_easy;
            required_time += (1 ^ t[i].second) * a + t[i].second * b;
            ++required_points;
        }
        printf("%lld\n", ans);
    }
}

/*
6 19 3 5
1 0 0 0 0 0 
1 18 19 1 6 3 

1 1 3 6 18 19
3 5
*/