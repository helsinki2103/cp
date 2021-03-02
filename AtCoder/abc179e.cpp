#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int64_t n, x, m; cin >> n >> x >> m;
    map<int, int> mp;
    vector<int> pref(m + 1, 0);
    pref[1] = x;
    mp[x] = 1;
    int l = -1, r = -1;
    for (int i = 2; i <= min(n, m); i++) {
        pref[i] = (pref[i - 1] % m * pref[i - 1] % m) % m;
        if (mp[pref[i]] == 0) {
            mp[pref[i]] = i;
        } else {
            l = mp[pref[i]];
            r = i - 1;
            break;
        }
    }
    if (r == -1) {
        int64_t sum = 0;
        for (int i = 1; i <= min(n, m); i++) sum += pref[i];
        cout << sum << '\n';
        return 0;
    }
    int64_t sum = 0;
    for (int i = 1; i < l; i++) sum += pref[i];
    int64_t len = r - l + 1;
    n -= (l - 1);
    int64_t t = n / len;
    int64_t rem = n % len;
    // cout << rem << '\n';
    for (int i = l; i <= r; i++) sum += 1ll * t * pref[i];
    for (int i = l; i < l + rem; i++) sum += pref[i];
    cout << sum << '\n';
    return 0;
}