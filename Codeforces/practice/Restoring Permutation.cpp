/**
 * @authors: https://github.com/macans
 * @date: 2020-05-05 00:49:20
 * codeforces-1315C
 * 贪心，优先队列
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
#define MAXN 1005
using namespace std;

priority_queue<int> cur;
int b[MAXN], a[2 * MAXN];
bool vis[MAXN * 2];
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
			cin >> b[i];
		}
		bool flag = false;
		for(int i = 0; i < n; i++){
			for(int j = b[i] + 1; j <= n << 1; j++){
				cur.push(-j);
			}
			memset(vis, 0, sizeof(vis));
			for(int j = i + 1; j < n; j++){
				vis[b[j]] = true;
			}
			for(int j = 0; j <= ((i - 1) << 1) + 1; j++){
				vis[a[j]] = true;
			}
			if(cur.empty()){
				flag = true;
				break;
			}
			int k = -cur.top();
			//printf("k=%d\n", k);
			while(!cur.empty() && vis[k]){
				cur.pop();
				k = -cur.top();
				//printf("k=%d\n", k);
			}
			while(!cur.empty()){
				cur.pop();
			}
			if(vis[k]){
				flag = true;
				break;
			}
			a[(i << 1)] = min(b[i], k);
			a[(i << 1) | 1] = max(b[i], k);
			//printf("i=%d,k=%d,b[i]=%d,a[i*2]=%d,a[i*2+1]=%d\n", i, k, b[i], a[i << 1], a[(i << 1) | 1]);
		}
		if(flag){
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < (n << 1); i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}