#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, r; cin >> n >> r;
    vector<pair<int, int> > a, b;
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        if (y>=0) a.push_back({x, y});
        else b.push_back({max(x, -y), y});
    }
    int cnt = 0;
    sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++) {
        if (r >= a[i].first) {
            r += a[i].second;
            ++cnt;
        }
    }
    vector<vector<int> > dp((int)b.size() + 1, vector<int>(r + 1, 0));
    dp[0][r] = cnt;
    sort(b.begin(), b.end(), cmp);
    for(int i=0; i<b.size(); i++) {
        for(int j=0; j<=r; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j >= b[i].first && j + b[i].second >= 0) {
                dp[i + 1][j + b[i].second] = max(dp[i + 1][j + b[i].second], dp[i][j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=r; i++) ans = max(ans, dp[(int)b.size()][i]);
    cout << ans;
    return 0;
}