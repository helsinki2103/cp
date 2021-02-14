#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0 ; i < n; i++) cin >> a[i];
        int64_t sum = accumulate(a.begin(), a.end(), 0ll);
        int64_t xorsum = 0;
        for (int i = 0; i < n; i++) xorsum ^= a[i];
        cout << "2\n" << xorsum << " " << sum + xorsum << '\n';
    }
    return 0;
}