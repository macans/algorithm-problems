/**
 * @authors: https://github.com/macans
 * @date: 2020-05-07 19:54:29
 * 
 * Hashtable
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

class FreqStack {
private:   
    vector<vector<int>> element;
    map<int, int> cnt;
    int n;
public:
    FreqStack() {
        element.clear();
        cnt.clear();
    }
    
    void push(int x) {
        if(cnt.find(x) == cnt.end()){
            if(element.empty()){
                element.push_back({});
            }
            element[0].push_back(x);
            cnt[x] = 1;
            return;
        }
        int t = cnt[x] + 1;
        if(element.size() < t){
            element.push_back({});
        }
        element[t - 1].push_back(x);
        //cout << t - 1 << " " << x << "\n";
        cnt[x] = t;
    }
    
    int pop() {
        
        int x = element.back()[element.back().size() - 1];
        element.back().pop_back();
        
        if(element.back().size() == 0){
            element.pop_back();
        }
        cnt[x]--;
        if(cnt[x] == 0){
            cnt.erase(x);
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	
}