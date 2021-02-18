#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        int ans = 0;
        vector<int> cnt(3, 0);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x %= 3;
            cnt[x]++;
        }
        int c = 0;
        for (int i = 0; ; i++) {
            if (cnt[i % 3] < n / 3) {
                c = 0;
                continue;
            } else if (cnt[i % 3] == n / 3) {
                c++;
                if (c == 3) break;
            } else {
                ans += cnt[i % 3] - n / 3;
                cnt[(i + 1) % 3] += (cnt[i % 3] - n / 3);
                cnt[i % 3] = n / 3;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}