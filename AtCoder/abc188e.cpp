#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> a(n), dp(n, -inf);
    rep(i,n) cin >> a[i];
    rep(i,m) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
    }
    int ans = -inf;
    ford(i,n-1,0) {
        for(int v: adj[i]) {
            dp[i] = max(dp[i], dp[v]);
        }
        ans = max(ans, dp[i] - a[i]);
        dp[i] = max(dp[i], a[i]);
    }
    cout << ans;
    return 0;
}