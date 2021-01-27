#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

vector<int> adj[N];
vector<int> color[2];
vector<bool> vis;

void dfs(int u, int pa = -1, int c = 0){
    color[c].push_back(u);
    for (int v: adj[u]){
        if (vis[v] || v==pa) continue;
        vis[v] = 1;
        dfs(v, u, 1 - c);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n, m; cin >> n >> m;
        vis.resize(n);
        for(int i=0; i<n; i++) adj[i].clear(), vis[i] = 0;
        for(int i=0; i<2; i++) color[i].clear();
        for(int i=0; i<m; i++){
            int u, v; cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis[0] = 1;
        dfs(0);
        if (color[0].size()>color[1].size()) swap(color[0], color[1]);
        cout << color[0].size() << '\n';
        for(int x: color[0]) cout << x + 1 << " ";
        cout << '\n';
    }
    return 0;
}