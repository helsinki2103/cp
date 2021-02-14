#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        
        vector<int> bit(54, 0);
        for (int i = 0; i < n; i++) {
            int64_t x; cin >> x;
            int cnt = 0;
            while (x) {
                bit[cnt++] += x % k;
                x /= k;
            }
        }
        bool f = 1;
        for (int i = 0; i < 54; i++) f &= (bit[i] <= 1);
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}