#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t n; cin >> n;
        int64_t l = 0, r = 1e9;
        while (l <= r) {
            int64_t mid = (l + r) >> 1ll;
            int64_t sum = mid * mid + (mid + 1) * (mid + 1);
            if (sum > n) r = mid - 1;
            else l = mid + 1;
        }
        cout << r << '\n';
    }
    return 0;
}