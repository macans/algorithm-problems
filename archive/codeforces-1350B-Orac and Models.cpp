/**
 * @authors: https://github.com/macans
 * @date: 2020-05-12 22:22:26
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
#define MAXN 100005
using namespace std;

int a[MAXN], f[MAXN];

int main(){
#ifdef OPEN_FILE
	//freopen("in.txt", "r", stdin);
#endif 
	int t;
	cin >> t;
	int n;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int ans = 1;
		f[1] = 1;
		for(int i = 2; i <= n; i++){
			f[i] = 1;
			for(int j = 1; j <= sqrt(i); j++){
				if(i % j == 0){
					if(a[i] > a[j]){
						f[i] = max(f[i], f[j] + 1);
					}
					if(a[i] > a[i / j]){
						f[i] = max(f[i], f[i / j] + 1);
					}
				}
			}
			ans = max(ans, f[i]);
		}
		cout << ans << "\n";
	}
}