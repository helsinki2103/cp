#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int n;
int a[N];
int cnt[N];

bool check (int x, int y) {
    memset(cnt,0,sizeof cnt);
    // cout << x << " " << y << '\n';
    for (int i = x; i < y; i++) cnt[a[i]]++;
    for (int i = 1; i <= y - x; i++) if (cnt[i] != 1) return false;
    
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int mx = *max_element(a, a + n);
        set<pair<int, int> > s;
        if (check(0, mx) && check(mx, n)) s.insert({mx, n - mx});
        if (check(0, n - mx) && check(n - mx, n)) s.insert({n - mx, mx});
        cout << s.size() << '\n';
        for (pair<int, int> p: s) cout << p.first << " " << p.second << '\n';
    }
    return 0;
}