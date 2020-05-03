/**
 * @authors: https://github.com/macans
 * @date: 2020-05-03 13:37:25
 * 
 * 构造
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
	int u, v;
	cin >> u >> v;
	if(u > v || ((v - u) & 1)){
		cout << -1 << endl;
		return 0;
	}
	if(u == 0)
	if(u == v){
		printf("1\n%d\n", u);
		return 0;
	}
	int x = (v - u) >> 1;
	if((u ^ x )== u + x){
		printf("2\n%d %d\n", u + x, x);
	}
	else{		
		printf("3\n%d %d %d\n", u, x, x);
	}
}