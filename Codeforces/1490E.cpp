#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> pref(n + 1, 0);
        vector<pair<int64_t, int> > a(n + 1);
        a[0].first = 0;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i].first;
        }
        vector<int> l(n + 1), r(n + 1);
        for (int i = n; i >= 1; i--) {
            r[i] = i;
            while (r[i] < n && a[r[i] + 1].first <= pref[i]) r[i] = r[r[i] + 1];
        }
        for (int i = 1; i <= n; i++) if (r[i] == n) ans.push_back(a[i].second);
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int x: ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}