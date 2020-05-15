/**
 * @authors: https://github.com/macans
 * @date: 2020-05-14 22:40:45
 * 
 * choose largest K elements from array a[] and b[], then choose remaining element from array a[]
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

int a[50], b[50];
int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	int t;
	cin >> t;
	int n, k;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n);
		int cnt = 0;
		int ans = 0;
		int i = n - 1, j = n - 1;
		while(cnt != n){
			if(a[i] < b[j] && k > 0){
				ans += b[j--];
				k--;
			}
			else{
				ans += a[i--];
			}
			
			++cnt;
			//cout << ans << " " << cnt << "\n";
		}
		cout << ans << "\n";
	}
}