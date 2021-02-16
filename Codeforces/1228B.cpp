#include<bits/stdc++.h>

using namespace std;
const int64_t mod = 1e9 + 7;

int64_t pow(int64_t a, int64_t b) {
    if (b == 0) return 1;
    int64_t tmp = pow(a, b/2) % mod;
    if (b % 2 == 0) return (tmp * tmp) % mod;
    return (tmp * tmp * a) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int h, w; cin >> h >> w;
    vector<int> r(h + 1), c(w + 1);
    for (int i = 1; i <= h; i++) cin >> r[i];
    for (int i = 1; i <= w; i++) cin >> c[i];
    vector<vector<int> > used(h + 2, vector<int>(w + 2, -1));
    for (int i = 1; i <= h; i++) {
        used[i][r[i] + 1] = 0;
    }
    for (int j = 1; j <= w; j++) {
        used[c[j] + 1][j] = 0;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= r[i]; j++) {
            if (used[i][j] == -1) {
                used[i][j] = 1;
            } else if (used[i][j] != 1) {
                cout << 0;
                return 0;
            }
        }
    }
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= c[j]; i++) {
            if (used[i][j] == -1) {
                used[i][j] = 1;
            } else if (used[i][j] != 1) {
                cout << 0;
                return 0;
            }
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) ans += (used[i][j] == -1);
    }
    cout << pow(2ll, ans);
    return 0;
}