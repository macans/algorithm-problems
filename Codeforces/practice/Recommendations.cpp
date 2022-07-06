/**
 * @authors: https://github.com/macans
 * @date: 2020-05-05 02:07:55
 * 
 * 贪心，multiset
 * codeforces-1315D
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
#define MAXN 200005

using namespace std;

pp a[MAXN];
int b[MAXN];
multiset<int> s;

bool compare_first(pp &x, pp &y){
	return x.first < y. first;
}
bool compare_second(pp &x, pp &y){
	return x.second > y.second;
}

int main(){
#ifdef OPEN_FILE
	//freopen("in.txt", "r", stdin);
#endif 
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
	}
	for(int i = 0; i < n; i++){
		cin >> a[i].second;
	}
	sort(a, a + n, compare_first);
	b[0] = a[0].first;
	for(int i = 1; i < n; i++){
		b[i] = max(b[i - 1] + 1, a[i].first);
	}
	sort(a, a + n, compare_second);
	s.clear();
	for(int i = 0; i < n; i++){
		s.insert(b[i]);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		multiset<int>::iterator it = s.lower_bound(a[i].first);
		//printf("%d %d %d %d\n", *it, *it - a[i].first, a[i].first, a[i].second);
		ans += (ll)(*it - a[i].first) * a[i].second;
		s.erase(it);
	}

	cout << ans << endl;
}