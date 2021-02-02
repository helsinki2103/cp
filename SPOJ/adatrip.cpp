#include<bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
const int inf = 1e9;

struct myData{
    int u, w;
    bool operator < (const myData &oth) const{
        return w>oth.w;
    }
};

int n, m, q;
int dist[N];
vector<myData> adj[N];

void dijkstra(int x){
    priority_queue<myData> pq;
    pq.push({x, 0});
    for(int i=0; i<n; i++) dist[i] = inf;
    dist[x] = 0;
    while (pq.size()){
        int u = pq.top().u;
        int du = pq.top().w;
        pq.pop();
        if (dist[u]!=du) continue;
        for(myData cur: adj[u]){
            int v = cur.u;
            int w = cur.w;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
    // for(int i=0; i<n; i++) cout << dist[i] << " ";
    // cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m >> q;
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    while (q--){
        int x; cin >> x;
        dijkstra(x);
        int res = -1, cnt = 0;
        for(int i=0; i<n; i++){
            if (dist[i]!=inf && dist[i]>res){
                res = dist[i];
                cnt = 1;
            }
            else if (dist[i]==res) ++cnt;
        }
        cout << res << " " << cnt << '\n';
    }
    return 0;
}