/**
 * @authors: https://github.com/macans
 * @date: 2020-05-14 22:57:00
 * 
 * The distance distribution is like several squares around the center.
 * we just need calculate the element sum of square below.
 * 2 2 2 2 2
 * 2 1 1 1 2
 * 2 1 0 1 2
 * 2 1 1 1 2
 * 2 2 2 2 2 
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
	//freopen("in.txt", "r", stdin);
#endif 
	int t;
	ll n;
	cin >> t;
	while(t--){
		cin >> n;
		ll k = 1, ans = 0;
		while(k < n){
			k += 2;
			ans += (k >> 1) * ((k - 1) << 2);
		}
		cout << ans << "\n";
	}
}