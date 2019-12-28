#include <cstdio>

using namespace std;

int main(){
    freopen("in.txt", "w", stdout);
    printf("1\n200000 9999 2\n");
    for(int i = 0; i < 200000; i++){
        printf("%d ", 10000);
    };
    fclose(stdout);
}