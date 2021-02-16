#include<bits/stdc++.h>

using namespace std;
const double EPS = 1e-3;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int x; cin >> x;
        cout << fixed << setprecision(8) << 1.0 / tan(4.0 * atan(1.0) / (2.0 * x)) << '\n';
    }
    return 0;
}