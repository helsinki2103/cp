#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // solution 1: deque
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        l[i] = i;
        while (l[i] > 1 && a[l[i] - 1] >= a[i]) l[i] = l[l[i] - 1];
    }
    for (int i = n; i >= 1; i--) {
        r[i] = i;
        while (r[i] < n && a[r[i] + 1] >= a[i]) r[i] = r[r[i] + 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, a[i] * (r[i] - l[i] + 1));

    // solution 2: naive
    // int ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     int l = i, r = i;
    //     while (l > 1 && a[l - 1] >= a[i]) --l;
    //     while (r < n && a[r + 1] >= a[i]) ++r;
    //     ans = max(ans, a[i] * (r - l + 1));
    // }

    // both solutions are accepted
    cout << ans;
    return 0;
}