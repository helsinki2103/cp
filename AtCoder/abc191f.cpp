#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> t;
    int mina = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i] && j < mina; j++) {
            if (a[i] % j == 0) {
                t[j] = gcd(a[i], t[j]);
                if (a[i] / j < mina) t[a[i] / j] = gcd(a[i], t[a[i] / j]);
            }
        }
    }
    int ans = 1;
    for (auto [x, y]: t) {
        ans += (x == y);
    }
    cout << ans << '\n';
    return 0;
}