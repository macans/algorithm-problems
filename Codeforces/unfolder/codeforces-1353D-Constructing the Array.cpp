/**
 * @authors: https://github.com/macans
 * @date: 2020-05-14 23:09:56
 * 
 * Use priority queue to maintain the pair value (length, start_position)
 * The first element is (n, 0)
 * We overwrite the comparator and choose the largest and most left one from priority queue
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
#define MAXN 200005
using namespace std;

struct compare{
    bool operator()(pp &a, pp &b){
		return a.first < b.first || (a.first == b.first && a.second > b.second);
    }
};

priority_queue<pp, vector<pp>, compare> q;
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
		q.push(make_pair(n, 0));
		int cnt = 1;
		while(!q.empty()){
			pp x = q.top(); q.pop();
			int mid = x.second + (x.first - 1) / 2;
			a[mid] = cnt++;
			//cout << "left =" << x.second << "len=" << x.first << "mid=" << mid << "\n";
			if(mid > x.second){
				//cout << "left push: " << mid - x.second <<", " << x.second << "\n";
				q.push(make_pair(mid - x.second, x.second));
			}
			if(mid < x.second + x.first - 1){
				//cout << "right push: " << x.second + x.first - mid - 1 << ", " << mid + 1 << "\n";
				q.push(make_pair(x.second + x.first - mid - 1, mid + 1));
			}
		}
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}