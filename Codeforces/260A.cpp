#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, n; cin >> a >> b >> n;
    for (int i = 0; i <= 9; i++) {
        int aa = a * 10 + i;
        if (aa % b == 0) {
            cout << aa;
            for (int i = 0; i < n - 1; i++) cout << 0;
            return 0;
        }
    }
    cout << -1;
    return 0;
}