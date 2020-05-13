/**
 * @authors: https://github.com/macans
 * @date: 2020-05-10 22:46:11
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
#include <unordered_map>
#define ll long long
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define OPEN_FILE
#define pp pair<int, int>
#define MAXN 
using namespace std;

class Solution {
private:
    const string hostName = "http://tiny.com/";
    const char *corpus = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<int, string> urls;
    long long id = 0L;
    
public:

    // Encodes a URL to a shortened URL.
    string toBase62(long long x){
        string y;
        while(true){
            y.push_back(corpus[x % 62]);
            x /= 62;
			if(x == 0) break;
        }
		string res;
		for(int i = y.size() - 1; i >= 0; i--){
			res.push_back(y[i]);
		}
        return res;
    }
    
    long long toBase10(string x){
        long long y = 0;
        int k = 0;
        while(k < x.size()){
            long long t;
            if(x[k] >= '0' && x[k] <= '9'){
                t = x[k] - '0' + 52;
            }
            else if(x[k] >= 'a' && x[k] <='z'){
                t = x[k] - 'a';
            }
            else {
                t = x[k] - 'A' + 26;
            }
            y = y * 62 + t;
            ++k;
        }
        return y;
    }
    
    string encode(string longUrl) {
        urls[id] = longUrl;
        return hostName + toBase62(id++); 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string base62 = shortUrl.substr(hostName.size(), shortUrl.size() - hostName.size());
        long long curId = toBase10(base62);
        return urls[curId];
    }
};

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	Solution s;

}