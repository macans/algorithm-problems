/**
 * @authors: https://github.com/macans
 * @date: 2020-04-26 00:05:39
 * codeforces-1323C
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
#define MAXN 1000005
using namespace std;

string s;

int main(){
#ifdef OPEN_FILE
    //freopen("in.txt", "r", stdin);
#endif 
    int n;
    cin >> n;
    cin >> s;
    int ans = 0, cnt = 1, right = 0, left = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            ++left;
        }
        else{
            --left;
        }
        if(left < 0){
            ++cnt;
        }
        //cout << left << ", ";
        if(left == 0 && cnt != 1){
            ans += cnt;
            cnt = 1;
        }
    }
    if(left != 0){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}