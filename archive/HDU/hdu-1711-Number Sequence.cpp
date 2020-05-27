/**
 * @authors: https://github.com/macans
 * @date: 2020-05-27 12:30:53
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

int a[MAXN], b[10005];
int Next[10005];

/*
ababc
00120
*/
int kmp(int *s, int n, int *p, int m){
	Next[0] = -1;
	int j = -1;
	for(int i = 1; i < m; i++){
		while(j >= 0 && p[j + 1] != p[i]) j = Next[j];
		if(p[j + 1] == p[i]) Next[i] = ++j;
	}
	
	j = -1;
	int res = -1;
	for(int i = 0; i < n; i++){
		while(j >= 0 && p[j + 1] != s[i]) j = Next[j];
		if(p[j + 1] == s[i]){
			j++;
		}
		if(j == m - 1){
			res = i - m + 2;
			break; 
		}
	}
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	ios_base::sync_with_stdio(0);
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		cout << kmp(a, n, b, m) << "\n";
	}
}