#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t n; cin >> n;
        int64_t sum = 0;
        while (n) {
            sum += n;
            n >>= 1;
        }
        cout << sum << '\n';
    }
    return 0;
}