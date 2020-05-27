/**
 * @authors: https://github.com/macans
 * @date: 2020-05-27 11:59:06
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

int a[MAXN], b[MAXN];

int partition(int* a, int left, int right){
	int x = a[(left + right) >> 1];
	int i = left, j = right;
	while(true){
		while(a[i] < x) ++i;
		while(a[j] > x) --j;
		if(i >= j) return j;
		swap(a[i], a[j]);
		++i;
		--j;
	}
}

void quick_sort(int* a, int left, int right){
	if(left >= right) return;
	int p = partition(a, left, right);
	quick_sort(a, left, p);
	quick_sort(a, p + 1, right);
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif 
	ios_base::sync_with_stdio(0);
	int n, m;
	while(cin >> n >> m){
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		quick_sort(a, 0, n - 1);
		for(int i = n - 1; i > n - m; i--){
			cout << a[i] << " ";
		}
		cout << a[n - m] << "\n";
	}
}