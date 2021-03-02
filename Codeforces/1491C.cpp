#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define fore(i,a,b) for (int i = (a); i <= (b); i++)
#define ford(i,a,b) for (int i = (a); i >= (b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        ll ans = 0;
        vector<ll> has(n, 0ll);
        rep(i,n) {
            int need = a[i] - 1 - has[i];
            if (need > 0) {
                ans += need;
                has[i] += need;
            }
            if (i + 1 < n) has[i + 1] += has[i] - a[i] + 1;
            fore(j,i+2,min(n-1,a[i]+i)) has[j]++;
        }
        cout << ans << '\n';
    }
    return 0;
}