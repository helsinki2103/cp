#include<bits/stdc++.h>

using namespace std;
const int N = 3e4 + 5;

vector<int> adj[N], st;
bool vis[N];
int pa[N], active[N];
int cnt[N];
int n, m;

int root(int x){
    return pa[x]==x ? x : pa[x] = root(pa[x]);
}

void dfs(int u){
    vis[u] = 1;
    pa[u] = u;
    st.push_back(u);
    for(int v: adj[u]){
        if (vis[v]){
            v = root(active[v]);
            while (st.back()!=v){
                pa[root(st.back())] = v;
                st.pop_back();
            }
        }
    }
    for(int v: adj[u]){
        if (!vis[v]){
            active[u] = v;
            dfs(v);
        }
    }
    if (st.back()==u) st.pop_back();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    if (m==0){
        cout << 1;
        return 0;
    }
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if (!vis[i]) dfs(i);
    }
    for(int i=1; i<=n; i++) cnt[root(i)]++;
    cout << 1 + *max_element(cnt+1,cnt+n+1);
    return 0;
}