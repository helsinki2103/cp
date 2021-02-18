#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int64_t> pref(n);
    sort(a.begin(), a.end());
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += pref[n - 1] - pref[i] - (n - i - 1) * a[i];
    }
    cout << ans;
    return 0;
}