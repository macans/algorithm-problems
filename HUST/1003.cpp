/**
 * @author macinchang
 * Created on  2022-03-11 01:03:03 
 */

#include <cstdio>

int main() {
    int t;
    double x;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf", &x);
        if(x < 0) {
            printf("0\n");
            return 0;
        }
        if(x < 1) {
            printf("1\n");
            return 0;
        }
        
    }
    return 0;
}
