/**
 * @authors: https://github.com/macans
 * @date: 2020-05-12 21:46:18
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
#define MAXN  1000005
using namespace std;

int f[MAXN];
int main(){
#ifdef OPEN_FILE
	//freopen("in.txt", "r", stdin);
#endif 
	int t;
	ll n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(!(n & 1)){
			cout << n + (k << 1) << "\n";
			continue;
		}
		ll j = 2;
		while(j < sqrt(n)){
			if(n % j == 0) break;
			j++;
		}
		ll x = j;
		if(n % j != 0){
			x = n;
		}
		cout << n + x + ((k - 1) << 1) << "\n";
	}
}