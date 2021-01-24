#include<bits/stdc++.h>

using namespace std;

int n;
int sX, ans = 0;
vector<vector<int> > adj;

void dfs(int u, int h, int pa = -1){
    if (h>ans){
        ans = h;
        sX = u;
    }
    for(int v: adj[u]){
        if (v==pa) continue;
        dfs(v, h + 1, u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    adj.resize(n);
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    ans = 0;
    dfs(sX, 0);
    cout << ans;
    return 0;
}