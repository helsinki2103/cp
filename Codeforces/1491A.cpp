#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> cnt(2, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            --x;
            cnt[a[x]]--;
            a[x] = 1 - a[x];
            cnt[a[x]]++;
        } else {
            if (cnt[1] >= x) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    return 0;
}