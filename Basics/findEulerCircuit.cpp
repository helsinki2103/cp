#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    vector<set<int> > adj(n + 1);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> st, ans;
    vector<bool> vis(n + 1, 0);
    st.push_back(1);
    while (st.size()){
        int u = st.back();
        vis[u] = 1;
        if (adj[u].empty()){
            st.pop_back();
            ans.push_back(u);
        }
        else{
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            st.push_back(v);
        }
    }
    for(int x: ans) cout << x << " ";
    return 0;
}