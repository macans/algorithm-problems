#include <cstdio>

using namespace std;

int main(){
    freopen("in.txt", "w", stdout);
    printf("1\n200000 1000000000 200000\n");
    for(int i = 0; i < 200000; i++){
        printf("%d ", 1);
    };
    fclose(stdout);
}