/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-11-18 22:56:35
   *  File : leetcode-c.cc
   ********************************************/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// class Solution {
//     int next[50005];
// public:
//         vector<int> findSubstring(string s, vector<string>& words) {
//             unordered_map<string, int> cnt;
//             for(int i = 0; i < words.size(); i++){
//                 cnt[words[i]]++;
//             }
//             int m = words[0].size(), n = words.size(); 
//             vector<int> ans;
//             for(int i = 0; i < s.length() - n * m + 1; i++){
//                 unordered_map<string, int> res;
//                 bool flag = true;
//                 for(int j = 0; j < m; j++){
//                     string tmp = s.substr(i + j * m, m);
//                     if(cnt.find(tmp) != cnt.end()){
//                         res[tmp]++;
//                         if(res[tmp] > cnt[tmp]) {
//                             flag = false;
//                             break;
//                         }
//                     }
//                     else {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag){
//                     ans.push_back(i);
//                 }
//             }
//             return ans;
//         }
// /*
//     int kmpMatch(string pat, string text){
//         memset(next, 0, sizeof(next));
//         int j = -1;
//         for(int i = 1; i < pat.length(); i++){
//             while(j > 0 && pat[j + 1] != pat[i]) j = next[j];
//             if(pat[j + 1] == pat[i]){
//                 next[i] = ++j;
//             }
//         }
//         j = -1;
//         for(int i = 0; i < text.length(); i++){
//             while(j > 0 && pat[j + 1] != text[i]) j = next[j];
//             if(pat[j + 1] == text[i]){
//                 j++;
//             }
//             if(j == pat.length() - 1){
//                 return i;
//             }
//         }
//         return -1;
//     };

//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> ans;
//         for(int i = 0; i < words.size(); i++){
//             int k = kmpMatch(words[i], s);
//             if(k >= 0){
//                 ans.push_back(k);
//             }
//         }
//         return ans;
//     }
//     */

// };


class Solution {
public:
        vector<int> findSubstring(string s, vector<string>& words) {
            unordered_map<string, int> cnt;
            for(int i = 0; i < words.size(); i++){
                cnt[words[i]]++;
            }
            int m = words[0].size(), n = words.size(); 
            vector<int> ans;
            for(int i = 0; i < s.length() - n * m + 1; i++){
                unordered_map<string, int> res;
                bool flag = true;
                for(int j = 0; j < m; j++){
                    string tmp = s.substr(i + j * m, m);
                    if(cnt.find(tmp) != cnt.end()){
                        res[tmp]++;
                        if(res[tmp] > cnt[tmp]) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(i);
                }
            }
            return ans;
        }
};

int main(){
    Solution s;
    vector<string> words;
    words.push_back("foo");
    s.findSubstring("foobar", words);
	return 0;
}
