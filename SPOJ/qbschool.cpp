#include<bits/stdc++.h>

using namespace std;
const int64_t inf = 1e18;
const int N = 5005;

struct Dijkstra{
    int u;
    int64_t d;
    bool operator < (const Dijkstra &oth) const{
        return oth.d>d;
    }
};

int64_t dist[N], dp[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int64_t> > > adj(n + 1);
    for(int i=0; i<m; i++){
        int t, u, v, l;
        cin >> t >> u >> v >> l;
        adj[u].push_back({v, l});
        if (t==2) adj[v].push_back({u, l});
    }
    //khoi tao
    for(int i=1; i<=n; i++){
        dp[i] = 0;
        dist[i] = inf;
    }
    dp[1] = 1; dist[1] = 0; 
    //dijkstra
    priority_queue<Dijkstra> pq;
    pq.push({1, 0});
    while (pq.size()){
        int u = pq.top().u;
        int cur = pq.top().d;
        pq.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            int64_t w = adj[u][i].second;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                dp[v] = dp[u];
                pq.push({v, dist[v]});
            }
            else if (dist[v]==dist[u] + w){
                //tong so duong di ngan nhat tu 1 den v cong voi tong so duong di ngan nhat tu 1 den u
                dp[v] += dp[u];
            }
        }
    }
    cout << dist[n] << " " << dp[n];
    return 0;
}