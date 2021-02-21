#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t n, k; cin >> n >> k;
        if (n > k) {
            int64_t t = n / k + (n % k != 0);
            k *= t;
        }
        int64_t ans = k / n;
        int64_t r = k % n;
        ans += r / n + (r % n != 0);
        cout << ans << '\n';
    }
    return 0;
}