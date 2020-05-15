/**
 * @authors: https://github.com/macans
 * @date: 2020-05-07 23:06:09
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

class Solution {
public:
    string toStr(long long x){
        string s;
        if(x == 0) return "0";
        while(x != 0){
            s.push_back(x % 10 + '0');
            x /= 10;
        }
        string res;
        for(int i = s.length() - 1; i >= 0; i--){
            res.push_back(s[i]);
        }
        return res;
    }
    
    string fractionToDecimal(int p, int q) {
        long long a = p, b = q;
        //a / b
        string ans;
        if(a < 0 && b < 0){
            a = -a;
            b = -b;
        }
        if(a * b < 0){
            ans = "-";
            a = max(a, -a);
            b = max(b, -b);
        }
        ans += toStr(a / b);
        a %= b;
        
        if(a == 0){
            return ans;
        }
        
        ans.push_back('.');
        
        map<int, int> s;
        int x, y;
        map<int,int>::iterator k;
        string decimal;
        while(true){
            x = (a * 10) / b;
            y = (a * 10) % b;
            s[a] = decimal.size();
            
            decimal.push_back(x + '0');
            if(y == 0) break;
            k = s.find(y);
            if(k != s.end()){
                break;
            }
            a = y;
        }
		
        if(y != 0){
            for(int i = 0; i < decimal.size(); i++){
                if(i == k->second ){
                    ans.push_back('(');
                }
                ans.push_back(decimal[i]);
            }
            ans.push_back(')');
        }
        else{
            ans += decimal;
        }
        return ans;
    }
};

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	
}