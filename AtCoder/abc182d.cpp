#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t ans = 0;
    int64_t sum = 0, csum = 0, maxsum = 0;
    for (int i = 1; i <= n; i++) {
        int64_t x; cin >> x;
        sum += x;
        maxsum = max(maxsum, sum);
        ans = max(ans, csum + maxsum);
        csum += sum;
    }
    cout << ans << '\n';
    return 0;
}