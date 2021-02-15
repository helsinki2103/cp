#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    x *= 100;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cur += a * b;
        if (cur > x) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}