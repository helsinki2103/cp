#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    set<int> s;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if (s.size() && a[i] - *s.begin() + 1 > m) s.erase(s.begin());
        if (s.size() < k - 1) s.insert(a[i]);
        else ans++;
    }
    cout << ans;
    return 0;
}