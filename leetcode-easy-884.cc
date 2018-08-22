/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-8-19 00:36:05
   *  File : leetcode-884.cc
   * 
   ********************************************/
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

class Solution1 {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        A += " " + B;
        std::vector<std::string> words;
        std::stringstream ss(A);
        std::string buff;
        while(ss >> buff) {
            words.push_back(buff);
        }
        std::unordered_map<std::string, int> counts;
        std::vector<std::string> uncommon;
        for(const string& word: words) {
            counts[word]++;
        }
        for(const string& word: words) {
            if(counts[word] == 1) {
                uncommon.push_back(word);
            }
        }
        return uncommon;
    }
};

class Solution2 {
public:
    inline void work(string a, unordered_map<string, int> &cnt){
        string str;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != ' '){
                str += a[i];
                continue;
            }
            cnt[str]++;
            str.clear();
        }
        cnt[str]++;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> cnt;
        work(A, cnt);
        work(B, cnt);
        unordered_map<string, int>::iterator it = cnt.begin();
        vector<string> res;
        while(it != cnt.end()){
            //printf("%s, %d\n", it->first.c_str(), it->second);
            if(cnt[it->first] <= 1){
                res.push_back(it->first);
            }
            ++it;
        }
        return res;
    }
};
int main(){
    Solution2 s;
    s.uncommonFromSentences("this apple is sweet", "this apple is hello");

	return 0;
}
