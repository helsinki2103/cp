#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            a[i] = c - '0';
        }
        for (int i = 1; i < n; i++) a[i] += a[i - 1];
        map<int, int> mp;
        mp[0] = 1;
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            mp[a[i] - i - 1]++;
        }
        for (auto [y, x]: mp) ans += 1ll * x * (x - 1) / 2ll;
        cout << ans << '\n';
    }
    return 0;
}