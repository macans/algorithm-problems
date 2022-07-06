/**
 * @authors: https://github.com/macans
 * @date: 2020-05-03 22:36:06
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

int main(){
#ifdef OPEN_FILE
	//freopen("in.txt", "r", stdin);
#endif 
	int t;
	cin >> t;
	int n, a[5];
	while(t--){
		cin >> n;
		for(int i = 0; i < 4; i++){
			cin >> a[i];
		}
		int l = a[2] - a[3], r = a[2] + a[3];
		int x = a[0] - a[1], y = a[0] + a[1];
		if(x * n <= r && y * n >= l){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		
	}
}