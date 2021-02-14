#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    char s[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> s[i][j];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int cnt = (s[i][j] == '#') + (s[i + 1][j] == '#');
            cnt += (s[i + 1][j + 1] == '#') + (s[i][j + 1] == '#');
            ans += cnt % 2;
        }
    }
    cout << ans;
    return 0;
}