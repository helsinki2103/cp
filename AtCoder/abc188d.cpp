#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t c; cin >> c;
    vector<pair<int64_t, int64_t> > event;
    for (int i = 0; i < n; i++) {
        int64_t l, r, x;
        cin >> l >> r >> x;
        event.push_back({l - 1, x});
        event.push_back({r, -x});
    }
    sort(event.begin(), event.end());
    int64_t ans = 0, cur = 0, t = 0;
    for (auto [x, y]: event) {
        if (x != t) {
            ans += min(c, cur) * (x - t);
            t = x;
        }
        cur += y;
    }
    cout << ans;
    return 0;
}