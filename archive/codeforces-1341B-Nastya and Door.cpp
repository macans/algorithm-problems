/**
 * @authors: https://github.com/macans
 * @date: 2020-05-03 22:55:10
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

int a[MAXN];
pp b[MAXN];
int main(){
#ifdef OPEN_FILE
	//freopen("in.txt", "r", stdin);
#endif 
	int t;
	cin >> t;
	int n, k;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int cur = 1;
		for(int i = 1; i < k - 1; i++){
			if(a[i] > a[i - 1] && a[i] > a[i + 1]){
				++cur;
			}
		}
		int ans = cur, ans_p = 0;
		//cout << ans << endl;
		for(int i = k - 1; i < n - 1; i++){
			if(a[i] > a[i - 1] && a[i] > a[i + 1]){
				++cur;
			}
			if(a[i - k + 2] > a[i - k + 1] && a[i - k + 2] > a[i - k + 3]){
				--cur;
			}
			if(cur > ans){
				ans = cur;
				ans_p = i - k + 2;
			}
			//cout << ans << " " << i - k + 1 << endl;
		}
		cout << ans << " " << ans_p + 1 << endl;
	}
}