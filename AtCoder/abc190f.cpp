#include<bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;

int bit[N];

int64_t query(int x) {
    int64_t ans = 0;
    while (x < N) {
        ans += bit[x];
        x += (x & -x);
    }
    return ans;
}

void upd(int x) {
    while (x) {
        bit[x]++;
        x -= (x & -x);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int64_t ans = 0;
    memset(bit,0,sizeof bit);
    for (int i = 0; i < n; i++) {
        ans += query(a[i] + 1);
        upd(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans << '\n';
        ans += n - 1 - 2ll * a[i];
    }
    return 0;
}