
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream> 

using namespace std;

int main(){
    int m, n, p, k;
    int a[200005], sum[200005];
    while(~scanf("%d", &m)){
        while(m--){
            scanf("%d%d%d", &n, &p, &k);
            for(int i = 0; i < n; i++){
                scanf("%d", &a[i]);
            }
            sort(a, a + n);
            for(int i = 0; i < k; i++){
                sum[i] = a[i];
            }
            for(int i = k; i < n; i++){
                sum[i] = sum[i -k] + a[i];
            }
            int left = 0, right = n;
            while(right - left > 1){
                int mid = (left + right) >> 1;
                if(sum[mid] > p){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            int ans = 0;
            if(sum[left] <= p){
                ans = left + 1;
            }
            printf("%d\n", ans);
        }
    }
}

