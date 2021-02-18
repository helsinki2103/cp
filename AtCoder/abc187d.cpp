#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    return a.first + a.first + a.second > b.first + b.first + b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int64_t, int64_t> > a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), cmp);
    int64_t cur = 0;
    for (int i = 0; i < n; i++) cur += a[i].first;
    int64_t sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cur -= a[i].first;
        sum += a[i].first + a[i].second;
        ans++;
        if (sum > cur) break;
    }
    cout << ans;
    return 0;
}