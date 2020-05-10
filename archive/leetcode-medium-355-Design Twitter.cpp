/**
 * @authors: https://github.com/macans
 * @date: 2020-05-10 16:35:34
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

map<int, vector<int> > m;

class Twitter {
private:
    int timestamp;
    map<int, vector< pair<int, int> > > tweets;
    map<int, set<int> > relations;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
        tweets.clear();
        relations.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(timestamp++, tweetId));
    }
    

 
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> res;
        for(int i = tweets[userId].size() - 1; i >= 0 && res.size() < 10; i--){
            res.push_back(tweets[userId][i]);
        }
        
        for(auto i = relations[userId].begin(); i != relations[userId].end(); i++){
            if(*i == userId) continue;
            vector<pair<int, int>> t = tweets[*i];
            for(int j = t.size() - 1; j >= 0; j--){
                if(res.empty()){
                    res.push_back(t[j]);
                    continue;
                }
                bool newer = false;
                for(int k = 0; k < res.size(); k++){
                    if(t[j].first > res[k].first){
                        res.insert(res.begin() + k, t[j]);
                        newer = true;
                        break;
                    }
                }
                if(!newer && res.size() < 10){
                    res.push_back(t[j]);
                }
                if(res.size() > 10) res.pop_back();
                if(!newer && res.size() >= 10) break;
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < res.size(); i++){
            ans.push_back(res[i].second);
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int a, int b) {
        relations[a].insert(b);
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int a, int b) {
        relations[a].erase(b);
    }
};



/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main(){
#ifdef OPEN_FILE
	freopen("in.txt", "r", stdin);
#endif 
	cout << m[1].size() << "\n";	
}
