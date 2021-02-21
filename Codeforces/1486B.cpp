#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        cout << (x[n / 2] - x[(n - 1)/2] + 1) * (y[n / 2] - y[(n - 1)/2] + 1) << '\n';
    }
    return 0;
}