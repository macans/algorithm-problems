/**
 * @authors: https://github.com/macans
 * @date: 2020-05-14 22:33:54
 * 
 * easy problem
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
	ll n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		if(n == 1) cout << "0\n";
		else if(n == 2) cout << m << "\n";
		else cout << (m << 1) << "\n";
	}
}