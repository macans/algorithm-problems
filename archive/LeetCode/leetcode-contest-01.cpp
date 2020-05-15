
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
    vector<vector<int> > shiftGrid(vector<vector<int> >& grid, int k) {
        if(grid.size() == 0) return grid;
        int n = grid.size(), m = grid[0].size();
        while(k--){
            vector<vector<int> > res = grid;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m - 1; j++){
                    res[i][j + 1] = grid[i][j];
                }
                if(i < n - 1){
                    res[i + 1][0] = grid[i][m - 1];
                }
            }
            res[0][0] = grid[n - 1][m - 1];
            grid = res;
        }
        return grid;
    }
};

int main(){
    Solution s;
    vector<int> a1;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);
    vector<int> a2;
    a2.push_back(4);
    a2.push_back(5);
    a2.push_back(6);
    vector<int> a3;
    a3.push_back(7);
    a3.push_back(8);
    a3.push_back(9);
    vector<vector<int> > a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    vector<vector<int> > b = s.shiftGrid(a, 1);
    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < b.size(); j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}


