/**
 * @authors: https://github.com/macans
 * @date: 2020-05-04 23:57:08
 * 
 * 简单题
 * codeforces-1315A
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
	cin >> t;
	int n, m, x, y;
	while(t--){
		cin >> n >> m >> x >> y;
		x++;
		y++;
		int ans = max(
			max((n - x) * m, (m - y) * n), 
			max((x - 1) * m, (y - 1) * n));
		cout << ans << endl;
	}
}