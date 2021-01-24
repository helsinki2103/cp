#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > adj;
vector<bool> vis;
bool f = 1;
int cnt = 0;

void dfs(int u, int pa = -1){
    if (!f) return;
    cnt++;
    for(int v: adj[u]){
        if (!vis[v]){
            vis[v] = 1;
            dfs(v, u);
        }
        else if (v!=pa) f = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    adj.resize(n);
    vis.resize(n);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<n; i++) vis[i] = 0;
    vis[0] = 1;
    dfs(0);
    if (!f || cnt!=n) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}