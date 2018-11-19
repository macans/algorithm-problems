/******************************************
*  Author : https://github.com/macans   
*  Created On : 2018-04-07
*  File : codeforces-954A.cpp
*******************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    char s[105];
    while(~scanf("%d", &n)){
        scanf("%s", s);
        int ans = n;
        bool flag = false;
        for(int i = 1; i < n; ++i){
            if(flag){
                flag = false;
                continue;
            }
            if((s[i] == 'R' && s[i - 1] == 'U') || (s[i] == 'U' && s[i - 1] == 'R')){
                --ans;
                flag = true;
            }
        }
        printf("%d\n", ans);
    }
}