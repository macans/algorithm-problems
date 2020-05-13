/******************************************
   *  Author : https://github.com/macans
   *  Created On : 2018-5-26 14:18:12
   *  File : tco.cc
   ********************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

int n, k, a[55], b[55], c[55];

double calc(ll x) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] + b[j] >= x) {
                c[i]++;
            }
        }
    }
    double z = 1;
    for (int i = 0; i < n; i++) {
        if (c[i] > i) {
            z *= c[i] - i;
        } else {
            return 0;
        }
    }
    return z;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    ll left = 0, right = 2e9 + 7;
    while (left < right - 1) {
        ll M = (ll)(left + right) / 2;
        if (calc(M) >= k) {
            left = M;
        } else {
            right = M;
        }
    }
    printf("%lld\n", left);
    return 0;
}
