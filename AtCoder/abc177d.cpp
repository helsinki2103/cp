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
    int n, m; cin >> n >> m;
    vector<map<int, int> > mp(n);
    vector<vector<int> > adj(n);
    rep(i,m) {
        int x, y; cin >> x >> y;
        --x; --y;
        if (!mp[x].count(y) && !mp[y].count(x)) {
            mp[x][y]++;
            mp[y][x]++;
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }
    vector<bool> vis(n, 0);
    ll ans = 0;
    rep(i,n) {
        if (vis[i]) continue;
        ll cnt = 0;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (sz(q)) {
            int u = q.front(); q.pop();
            cnt++;
            for (int v: adj[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}