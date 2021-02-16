#include<bits/stdc++.h>

using namespace std;
const int64_t inf = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int64_t sum = accumulate(a.begin(), a.end(), 0ll);
        int64_t k = max((int64_t)(sum + n - 1 - 1) / (n - 1), *max_element(a.begin(), a.end()));
        cout << k * (n - 1) - sum << '\n';
    }
    return 0;
}