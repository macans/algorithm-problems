/**
 * @authors: https://github.com/macans
 * @date: 2020-05-05 00:14:06
 * codeforces-1315B
 * 模拟
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
#define MAXN 10005
using namespace std;

string s;
int bus[MAXN];
int main(){
#ifdef OPEN_FILE
	//freopen("in.txt", "r", stdin);
#endif 
	int t;
	cin >> t;
	int a[2], p;
	int n = 0, cnt = 0;
	while(t--){
		cin >> a[0] >> a[1] >> p;
		cin >> s;
		n = s.length();
		int sum = 0, ans = 1;
		if(s[n - 1] == s[n - 2]){
			sum = a[s[n - 1] - 'A'];
			if(sum > p){
				cout << n << endl;
				continue;
			}
		}
		for(int i = s.length() - 1; i > 0; i--){
			//cout << sum << endl;
			if(s[i] == s[i - 1]) continue;
			
			if(a[s[i - 1] - 'A'] + sum <= p){
				sum += a[s[i - 1] - 'A'];
			}
			else{
				ans = i + 1;
				break;
			}
		}
		cout << ans << endl;
	}
}