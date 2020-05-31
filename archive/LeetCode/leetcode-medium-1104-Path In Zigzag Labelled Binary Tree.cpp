/**
 * @authors: https://github.com/macans
 * @date: 2020-05-30 22:04:41
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int depth = 0, x = 0, k = 1;
        while(x < label){
            x += k;
            k <<= 1;
            ++depth;
        }
        vector<int> res;
        x = label;
        res.push_back(x);
        while(--depth){
            if(depth & 1){
                x = ((1 << depth) + (1 << (depth + 1)) - 1 - x) >> 1;
            }
            else{
                x = (1 << (depth - 1)) + (1 << depth) - 1 - (x >> 1);
            }
            res.push_back(x);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){

}
