#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int64_t sum = 0;
        int64_t ans = 0;
        for (int i = 1; i < n; i++) {
            int64_t cur = c[i] + 1ll + abs(a[i] - b[i]);
            if (a[i] != b[i]) cur = max(cur, sum + c[i] + 1ll - abs(a[i] - b[i]));
            ans = max(ans, cur);
            sum = cur;
        }
        cout << ans << '\n';
    }
    return 0;
}