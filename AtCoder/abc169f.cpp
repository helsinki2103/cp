#include<bits/stdc++.h>

using namespace std;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<vector<int64_t> > dp(n + 1, vector<int64_t>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j] += 2ll * dp[i][j];
            dp[i + 1][j] %= mod;
            if (j + a[i] <= s) {
                dp[i + 1][j + a[i]] += dp[i][j];
                dp[i + 1][j + a[i]] %= mod;
            }
        }
    }
    cout << dp[n][s];
    return 0;
}