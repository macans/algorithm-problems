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
	int n = 1000000, m = 100;
	cout << n << " " << m << "\n";
	while(n--){
		cout << rand() % 1000000 - 500000 + 1 << " ";
	}
	cout << "\n";
    cout << endl;
    fclose(stdout);
}