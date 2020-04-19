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
#define OPEN_FILE
#define MAXN 200005

using namespace std;

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

int kmp_match(string pat, vector<string> texts){
    vector<int> _next;
    for(int i = 0; i < pat.size(); i++){
        pat[i] = tolower(pat[i]);
        _next.push_back(0);
    }
    
    for(int i = 0; i < texts.size(); i++){
        for(int j = 0; j < texts[i].size(); j++){
            texts[i][j] = tolower(texts[i][j]);
        }
    }
    
    int j = -1;
    for(int i = 1; i < pat.length(); i++){
        while(j > 0 && pat[j + 1] != pat[i]) j = _next[j];
        if(pat[j + 1] == pat[i]){
            _next[i] = ++j;
        }
    }
    int ans = 0;
    for(int p = 0; p < texts.size(); p++){
        j = -1;
        int cnt = 0;
        for(int i = 0; i < texts[p].length(); i++){
            while(j > 0 && pat[j + 1] != texts[p][i]) j = _next[j];
            if(pat[j + 1] == texts[p][i]){
                j++;
            }
            if(j == pat.length() - 1){
                ++cnt;
                j = _next[j - 1];
            }
        }
        cout << pat << " " << texts[p] << " " << cnt << endl;
        ans += cnt;
    }
    //printf("%s %s %d\n", pat.c_str(), text.c_str(), cnt);
    return ans;
};

bool toy_compare(pair<string, int> &a, pair<string, int> &b){
    return a.second > b.second || (a.second == b.second && a.first > b.first);
}

vector<string> popularNToys(int numToys, int topToys, 
							   vector<string> toys, 
							   int numQuotes,
							   vector<string> quotes)
{
    vector<pair<string, int> > toy_cnt;
    for(int i = 0; i < numToys; i++){
        toy_cnt.push_back(make_pair(toys[i], 0));
        toy_cnt[i].second = kmp_match(toys[i], quotes);
    }
    sort(toy_cnt.begin(), toy_cnt.end(), toy_compare);
    vector<string> ans;
    for(int i = 0; i < topToys; i++){
        ans.push_back(toy_cnt[i].first);
    }
    return ans;
}
// FUNCTION SIGNATURE ENDS


int main(){
#ifdef OPEN_FILE
   //freopen("in.txt", "r", stdin);
#endif 
    vector<string> toys;
    toys.push_back("hello");
    toys.push_back("gOod");
    toys.push_back("Yes");

    vector<string> quotes;
    quotes.push_back("hellogoodgood");
    quotes.push_back("goOdYES");
    quotes.push_back("YESYESYES");

    vector<string> ans = popularNToys(toys.size(), 2, toys, quotes.size(), quotes);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}

