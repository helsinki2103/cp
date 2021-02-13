#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t x, y; cin >> x >> y;
        int64_t res = 0;
        for (int i = 1; i*i <= x; i++) {
            res += max(0ll, min(y, x/i - 1) - i);
        }
        cout << res << '\n';
    }
    return 0;
}