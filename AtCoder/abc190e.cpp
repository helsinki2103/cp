#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

bool mini(int &a, int b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k; cin >> k;
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        --c[i];
    }
    auto bfs = [&](int s) {
        vector<int> cost(n, inf);
        cost[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v: adj[u]) {
                if (mini(cost[v], cost[u] + 1)) q.push(v);
            }
        }
        for (int i = 0; i < k; i++) cost[i] = cost[c[i]];
        cost.resize(k);
        return cost;
    };
    vector<vector<int> > cost(k);
    for (int i = 0; i < k; i++) cost[i] = bfs(c[i]);
    vector<vector<int> > dp(1 << k, vector<int>(k, inf));
    for (int i = 0; i < k; i++) dp[1 << i][i] = 1;
    for (int mask = 1; mask < (1 << k); mask++) {
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                int mask2 = mask ^ (1 << i);
                for (int j = 0; j < k; j++) {
                    if (mask2 & (1 << j)) {
                        mini(dp[mask][i], dp[mask2][j] + cost[i][j]);
                    }
                }
            }
        }
    }
    int ans = *min_element(dp.back().begin(), dp.back().end());
    if (ans >= inf) ans = -1;
    cout << ans;
    return 0;
}