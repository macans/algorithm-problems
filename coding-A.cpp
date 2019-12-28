#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b, c, r;
    while(~scanf("%d", &n)){
        while(n--){
            scanf("%d%d%d%d", &a, &b, &c, &r);
            if(a > b) swap(a, b);
            int left = max(c - r, a), right = min(c + r, b);
            if(left >= b || right <= a){
                printf("%d\n", b - a);
                continue;
            }
            printf("%d\n", max(0, left - a) + max(b - right, 0));
        }
    }
}
