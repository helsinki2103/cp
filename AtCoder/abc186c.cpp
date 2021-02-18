#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        bool f1 = 0;
        while (x) {
            int r = x % 10;
            f1 |= (r == 7);
            x /= 10;
        }
        bool f2 = 0;
        x = i;
        while (x) {
            int r = x % 8;
            f2 |= (r == 7);
            x /= 8;
        }
        ans += (!f1 && !f2);
    }
    cout << ans;
    return 0;
}