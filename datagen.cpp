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
    //freopen("in.txt", "w", stdout);
	int a[5][5] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 0, 0, 0, 0};
	int d[8] = {0};
	int cnt = 0;
    while(true){
		int i = 5 * ((rand() % 5) - 1) + (rand() % 5);
		if(i <= 21){
			d[i % 7 + 1]++;
			if(++cnt == 1000000) break;
		}
	}
	for(int i = 1; i < 8; i++){
		cout << i << " " << d[i] << "\n";
	}
}
