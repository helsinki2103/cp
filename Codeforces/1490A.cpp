#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> v(n);
        int ans = 0;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n - 1; i++) {
            int x = min(v[i], v[i + 1]);
            int y = max(v[i], v[i + 1]);
            while (y > 2 * x) {
                ans++;
                x *= 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}