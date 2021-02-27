#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t p, a, b, c; cin >> p >> a >> b >> c;
        int64_t t1 = (p - 1) / a + 1;
        int64_t t2 = (p - 1) / b + 1;
        int64_t t3 = (p - 1) / c + 1;
        cout << min({t1 * a, t2 * b, t3 * c}) - p << '\n';
    }
    return 0;
}