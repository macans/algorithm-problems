/**
 * @authors: https://github.com/macans
 * @date: 2020-05-12 20:53:57
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

int prime[MAXN];
bool isPrime[MAXN];
int len;

void get_prime(){
	len = 0;
	const int N = 200005;
	memset(isPrime, true, sizeof(isPrime));
	for(int i = 2; i <= N; ++i){
		if(isPrime[i]){
			prime[len++] = i;
			for(int j= (i << 1); j <= N; j += i)
				isPrime[j] = false;
		}
	}
}

ll a[MAXN];
vector<int> b[MAXN];

ll calc(ll x, ll y){
	ll res = 1;
	while(y--){
		res *= x;
	}
	return res;
}

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	//get_prime();
	int n;
	cin >> n;
	ll max_a = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll ans = 1;
	for(int i = 0; i < n; i++){
		ll j = 2, k = sqrt(a[i]);
		//cout << a[i] << " " << k << "\n";
		ll cnt, x = a[i];
		while(j <= k){
			cnt = 0;
			while(x % j == 0){
				x /= j;
				cnt++;
			}
			//cout << "j=" << j << ", " << cnt << "\n";
			if(cnt != 0){
				b[j].push_back(cnt);
				max_a = max(j, max_a);
			}
			j++;
		}
		if(x != 1){
			b[x].push_back(1);
			max_a = max(x, max_a);
		}
	}

	for(int i = 0; i <= max_a; i++){
		if(b[i].size() < n - 1) continue;
		sort(b[i].begin(), b[i].end());
		if(b[i].size() == n){
			ans *= calc(i, b[i][1]);
		}
		else{
			ans *= calc(i, b[i][0]);
		}
	}
	cout << ans << "\n";
}