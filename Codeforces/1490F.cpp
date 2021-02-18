#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (mp[a[i]] == 0) {
                mp[a[i]] = ++cnt;
                a[i] = cnt;
            } else a[i] = mp[a[i]];
        }
        n = *max_element(a.begin(), a.end());
        vector<int> tot(n + 1, 0);
        for (int x: a) tot[x]++;
        sort(tot.begin(), tot.end());
        vector<int> pref(n + 1, 0);
        vector<int> l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + tot[i];
        for (int i = n; i >= 1; i--) {
            r[i] = i;
            while (r[i] < n && tot[r[i] + 1] == tot[i]) r[i] = r[r[i] + 1];
        }
        for (int i = 1; i <= n; i++) {
            l[i] = i;
            while (l[i] > 1 && tot[l[i] - 1] == tot[i]) l[i] = l[l[i] - 1];
        }
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, pref[l[i] - 1] + pref[n] - pref[r[i]] - tot[i] * (n - r[i]));
        }
        cout << ans << '\n';
    }
    return 0;
}