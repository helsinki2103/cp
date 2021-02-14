#include<bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
const int inf = 1e9 + 5;

int n, k;
vector<int> adj[N];
int sz[N], dp[N];

void dfs(int u) {
    dp[u] = 0;
    sz[u] = 1;
    for (int v: adj[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    if (sz[u] >= k) {
        sz[u] = 0;
        dp[u] = 1;
    }
    for (int v: adj[u]) dp[u] += dp[v];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> k >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    cout << dp[1];
    return 0;
}