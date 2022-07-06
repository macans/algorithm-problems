/**
 * @authors: https://github.com/macans
 * @date: 2020-05-15 00:09:02
 * 
 * dp[i] means the minimal cost if let s[i] be '1'
 * then dp[i] = min(dp[i - k] + (s[i] != '1'), cntl[i - k] + (s[i] != '1')), cntl[i] means the count of '1' in the left and has same remainder when modulo k
 * 
 * res[i] means the minimal cost that let the string of which has same remainder with i%k be valid
 * 
 * res[i] = min(all values are '0', dp[i] + cntr[i + k])
 * 
 * the final answer will be 
 * ans = min(res[i] + total '1' numbers - '1' numbers that has differemce remainder with i%k)
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
#define pp pair<int, int>
#define MAXN 1000005
using namespace std;

string s;
int cntl[MAXN], cntr[MAXN], cnt[MAXN];
int dp[MAXN], res[MAXN];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	int t, n, k;
	int first, last;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cin >> s;
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += (s[i] == '1');
			cntl[i] = s[i] == '1';
			if(i >= k){
				cntl[i] += cntl[i - k];
			}
			cnt[i % k] = cntl[i];
		}

		for(int i = n - 1; i >= 0; i--){
			cntr[i] = s[i] == '1';
			if(i + k < n){
				cntr[i] += cntr[i + k];
			}
		}
		cntl[n] = cntr[n] = 0;		
		for(int i = 0; i < k; i++){
			dp[i] = (s[i] != '1');
			if(i + k < n){
				res[i] = min(cnt[i], dp[i] + cntr[i + k]);
			}
			else{
				res[i] = min(cnt[i], dp[i]);
			}
			//printf("cnt[i]=%d, cntr[i+k]=%d, res[i]=%d\n", cnt[i], cntr[i+k], res[i]);

		}
		for(int i = k; i < n; i++){
			//0 0 0 s[i]
			dp[i] = cntl[i - k] + (s[i] != '1');
			dp[i] = min(dp[i], dp[i - k] + (s[i] != '1'));
			if(i + k < n){
				res[i % k] = min(res[i % k], dp[i] + cntr[i + k]);
			}
			else{
				res[i % k] = min(res[i % k], dp[i]);
			}
			//printf("i=%d, dp[i]=%d, res[i]=%d\n", i, dp[i], res[i]);

		}
		int ans = INF;
		for(int i = 0; i < k; i++){
			//printf("res[i]=%d, cnt[i]=%d\n", res[i], cnt[i]);
			ans = min(ans, res[i] + sum - cnt[i]);
		}
		cout << ans << "\n";

	}
} 
