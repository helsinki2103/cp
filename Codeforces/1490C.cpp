#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t n; cin >> n;
        bool f = 0;
        for (int64_t i = 1; i * i * i <= n; i++) {
            int64_t l = i, r = 1e5;
            while (l <= r) {
                int64_t mid = (l + r) >> 1ll;
                int64_t sum = i * i * i + mid * mid * mid;
                if (sum == n) {
                    f = 1;
                    break;
                } else if (sum > n) r = mid - 1;
                else l = mid + 1;
            }
            if (f) break;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}