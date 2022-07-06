/**
 * @authors: https://github.com/macans
 * @date: 2020-05-03 11:09:31
 * codeforces-1332D
 * 矩阵构造
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
	freopen("in.txt", "r", stdin);
#endif 
	int k;
	int x = 1;
	cin >> k;
	while(x <= k){
		x <<= 1;
	}
	cout << "2 3" << endl;
	cout << x + k << " " << k << " " << 0 << endl;
	cout << x << " " << x + k << " " << k << endl;
}