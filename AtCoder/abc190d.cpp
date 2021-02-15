#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int64_t n; cin >> n;
    int64_t ans = 0;
    for (int64_t i = 1; i * i <= 2ll * n; i += 1) {
        ans += ((2ll * n) % i == 0 && ((2ll * n) / i) % 2 != (i % 2));
    }
    cout << ans * 2ll << '\n';
    return 0;
}