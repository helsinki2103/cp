#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool f = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < i) {
                f = 0;
                break;
            }
            a[i + 1] += a[i] - i;
            a[i] = i;
        }
        for (int i = 1; i < n; i++) {
            f &= (a[i] > a[i - 1]);
        }
        // for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}