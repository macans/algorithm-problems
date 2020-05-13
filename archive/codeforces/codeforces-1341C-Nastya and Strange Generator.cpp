/**
 * @authors: https://github.com/macans
 * @date: 2020-05-04 00:18:53
 * 
 * 置换
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

int a[MAXN];

int main(){
#ifdef OPEN_FILE
	//freopen("in.txt", "r", stdin);
#endif 
	int t;
	cin >> t;
	int n;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int k = 0, m = n;
		bool ans = true;
		while(k < n){
			if(a[k] == m){
				--m;
				++k;
				continue;
			}
			//printf("1 - k=%d,m=%d\n", k, m);
			int tmp = a[k] - 1;
			while(k < n - 1 && a[k + 1] - a[k] == 1){
				k++;
			}
			//printf("2- k=%d,m=%d\n", k, m);
			if(a[k] != m){
				ans = false;
				break;
			}
			m = tmp;
			++k;
		}
		printf("%s\n", ans ? "Yes" : "No");
	}
}