#include <cstdio>
#include <random>
#include <iostream>
#include <string>
#define MAXN 200000

using namespace std;


int main(){
    //freopen("in.txt", "w", stdout);
	for(int i = 1; i < 63; i++) {
		string s = "";
		int x = i;
		while(x > 0) {
			s.push_back((x % 2) + '0');
			x >>= 1;
		}
		s.reserve();
		cout << "1" << endl;
	}
}
