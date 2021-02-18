#include<bits/stdc++.h>

using namespace std;
int64_t dp[200][12];

int64_t calc(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    if (k == n) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = calc(n - 1, k - 1) + calc(n - 1, k);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    memset(dp,255,sizeof dp);
    cout << calc(n - 1, 11);
    return 0;
}