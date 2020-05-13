#include <cstdio>
#include <random>
#include <iostream>
#define MAXN 200000

using namespace std;

int prime[MAXN];
bool isPrime[MAXN];
int len;

void get_prime(){
	len = 0;
	const int N = 200000;
	memset(isPrime, true, sizeof(isPrime));
	for(int i = 2; i <= N; ++i){
		if(isPrime[i]){
			prime[len++] = i;
			for(int j= (i << 1); j <= N; j += i)
				isPrime[j] = false;
		}
	}
}

int main(){
    freopen("in.txt", "w", stdout);
	get_prime();
    int n = 200000;
	n--;
	cout << 10 << " ";
    while(n--){
        cout << 170777 << " ";
    }
    cout << endl;
    fclose(stdout);
}