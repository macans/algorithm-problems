#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define OPEN_FILE

using namespace std;

/**
 * @author macinchang
 * Created on  2022-07-17 17:43:48
 */
void solve() {
    int n;
    string s, letters;
    int m;
    bool mask[26];
    memset(mask, false, 26);
    cin >> n;
    cin >> s;
    cin >> m;
    getline(cin, letters);
    char ch;
    for (int i = 0; i < letters.size(); i++) {
        ch = letters[i];
        if (ch < 'a' || ch > 'z') {
            continue;
        }
        mask[ch - 'a'] = true;
    }
    int ans = 0;
    int last = 0;
    for (int i = 1; i < s.size(); i++) {
        if (mask[s[i] - 'a']) {
            ans = max(i - last, ans);
            last = i;
        }
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../../in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}