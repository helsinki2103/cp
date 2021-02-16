#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        int ans = 0;
        
        if (n % 2 ==0) ans = k % n;
        else {
            ans = ((2 * k - 1) / (n - 1) + k) % n;
            //if (k % n <= n / 2) ans++;
        }
        if (ans == 0) ans += n;
        cout << ans << '\n';
    }
    // int n, k; cin >> n >> k;
    // int x = 0, y = n - 1;
    // int cnt = 0;
    // for (int i = 1; i <= k; i++) {
    //     if (x == y) {
    //         cnt++;
    //         x++;
    //     }
    //     x++;
    //     y--;
    //     x %= n;
    //     y = (y + n) % n;
    // }
    // cout << cnt;
    return 0;
}