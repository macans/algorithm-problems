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
vector<int> lengthEachScene(vector<char> inputList) {
    // WRITE YOUR CODE HERE 
    int last[305];
    for(int i = 0; i < inputList.size(); i++){
        last[inputList[i]] = i;
    }
    vector<int> ans;
    int j = 0;
    while(j < inputList.size()){
        int cnt = 1;
        int k = last[inputList[j]];
        while(j != k){
            j++;
            cnt++;
            k = max(k, last[inputList[j]]);
            //printf("j=%d, k=%d\n", j, k);
        }
        //printf("%d\n", cnt);
        ans.push_back(cnt);
        j++;
    }
    return ans;
}
// FUNCTION SIGNATURE ENDS
int main(){
#ifdef OPEN_FILE
   //freopen("in.txt", "r", stdin);
#endif 
    string s = "a b c d a   e f  g hije";
    12
    5， 7
    vector<char> a;
    for(int i = 0; i < s.length(); i++){
        a.push_back(s[i]);
    }
    lengthEachScene(a);
}

