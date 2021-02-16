#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int> > a;
    for (int i = 1; i <= (1 << n); i++) {
        int x; cin >> x;
        a.push_back({i, x});
    }
    for (int i = 1; ; i++) {
        if (a.size() == 2) break;
        vector<pair<int, int> > cur;
        for (int j = 0; j < a.size(); j+=2) {
            if (a[j].second > a[j + 1].second) cur.push_back({a[j].first, a[j].second});
            else cur.push_back({a[j + 1].first, a[j + 1].second});
        }
        a = cur;
    }
    if (a[0].second > a[1].second) cout << a[1].first;
    else cout << a[0].first;
    return 0;
}