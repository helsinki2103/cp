#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(m + 2);
    a[0] = 0;
    a[m + 1] = n + 1;
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a.begin(),a.end());
    int minGap = inf;
    for (int i = 1; i <= m + 1; i++) {
        if (a[i] - a[i - 1] <= 1) continue;
        minGap = min(minGap, a[i] - a[i - 1] - 1);
    }
    // cerr << minGap;
    int ans = 0;
    for (int i = 1; i <= m + 1; i++) {
        if (a[i] - a[i - 1] <= 1) continue;
        ans += (a[i] - a[i - 1] - 2) / minGap + 1;
    }
    cout << ans;
    return 0;
}