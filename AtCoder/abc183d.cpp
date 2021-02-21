#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t w; cin >> w;
    vector<int64_t> a(N, 0);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        int64_t p; cin >> p;
        a[l] += p;
        a[r] -= p;
    }
    int64_t cur = 0;
    for (int i = 1; i < N; i++) a[i] += a[i - 1];
    for (int i = 0; i < N; i++) {
        if (a[i] > w) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}