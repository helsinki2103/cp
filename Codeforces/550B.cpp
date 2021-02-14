#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, l, r, x; cin >> n >> l >> r >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cur.push_back(a[i]);
        }
        bool f = 1;
        f &= (int(cur.size()) >= 2);
        f &= (accumulate(cur.begin(), cur.end(), 0) >= l);
        f &= (accumulate(cur.begin(), cur.end(), 0) <= r);
        f &= (*max_element(cur.begin(), cur.end()) - *min_element(cur.begin(), cur.end()) >= x);
        ans += f;
    }
    cout << ans;
    return 0;
}