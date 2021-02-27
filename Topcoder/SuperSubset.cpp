#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

class SuperSubset {
public:
    int solve(vector<int> a, int y) {
        int n = a.size();
        vector<vector<int64_t> > dp(n + 1, vector<int64_t>(y + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= y; j++) {
                dp[i + 1][j] += 2ll * dp[i][j];
                dp[i + 1][j] %= mod;
                if (j + a[i] <= y) {
                    dp[i + 1][j + a[i]] += dp[i][j];
                    dp[i + 1][j + a[i]] %= mod;
                }
            }
        }
        return dp[n][y];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    return 0;
}