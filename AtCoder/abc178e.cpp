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
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll maxZ = -inf, minZ = inf;
    ll maxW = -inf, minW = inf;
    rep(i,n) {
        ll x, y; cin >> x >> y;
        maxi(maxZ, x + y);
        mini(minZ, x + y);
        maxi(maxW, x - y);
        mini(minW, x - y);
    }
    cout << max(maxZ - minZ, maxW - minW);
    return 0;
}