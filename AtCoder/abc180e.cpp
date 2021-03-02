#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

bool mini(int &a, int b) { if (a > b) { a = b; return true; } return false; }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    auto calc = [&] (int a, int b) {
        return abs(x[a] - x[b]) + abs(y[a] - y[b]) + max(0, z[b] - z[a]);
    };
    vector<vector<int> > dp(n, vector<int>((1 << n), inf));
    dp[0][1] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                mini(dp[j][mask | (1 << j)], dp[i][mask] + calc(i, j));
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) ans = min(ans, dp[i][(1 << n) - 1] + calc(i, 0));
    cout << ans;
    return 0;
}