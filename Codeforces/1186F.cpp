#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > ans;
int n, m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    vector<set<int> > adj(n + 1);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=1; i<=n; i++){
        if (adj[i].size()&1){
            adj[i].insert(0);
            adj[0].insert(i);
        }
    }
    vector<bool> vis(n + 1, 0);
    for(int i=1; i<=n; i++){
        if (!vis[i]){
            vector<int> st;
            st.push_back(i);
            vector<int> cur;
            while (st.size()){
                int u = st.back();
                vis[u] = 1;
                if (adj[u].empty()){
                    st.pop_back();
                    cur.push_back(u);
                }
                else{
                    int v = *adj[u].begin();
                    adj[u].erase(v);
                    adj[v].erase(u);
                    st.push_back(v);
                }
            }
            cur.pop_back();
            for(int i=0; i<cur.size(); i++){
                int x = cur[(i - 1 + cur.size())%cur.size()];
                int y = cur[i];
                int z = cur[(i + 1)%cur.size()];
                int t = cur[(i + 2)%cur.size()];
                if (y==0 || z==0) continue;
                if (x==0 || t==0 || !(i&1)){
                    ans.push_back({y, z});
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x.first << " " << x.second << '\n';
    return 0;
}