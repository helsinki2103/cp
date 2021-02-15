#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m;
    vector<pair<int, int> > cond(m);
    for (int i = 0; i < m; i++) cin >> cond[i].first >> cond[i].second;
    cin >> k;
    vector<pair<int, int> > choice(k);
    for (int i = 0; i < k; i++) cin >> choice[i].first >> choice[i].second;
    int ans = 0;
    for (int mask = 0; mask < 1 << k; mask++) {
        vector<bool> f(n, 0);
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            pair<int, int> cur = choice[i];
            f[mask & 1 << i ? cur.first : cur.second] = 1;
        }
        for (int i = 0; i < m; i++) cnt += (f[cond[i].first] && f[cond[i].second]);
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}