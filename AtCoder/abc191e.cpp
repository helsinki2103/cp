#include<bits/stdc++.h>

using namespace std;
const int N = 2e3 + 5;
const int inf = 1e9;

struct myData{
    int v, w;
    bool operator < (const myData &oth) const {
        return w > oth.w;
    }
};

vector<pair<int, int> > adj[N];
int n, m;
int dist[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) dist[i][j] = inf;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        if (u == v) dist[u][u] = min(dist[u][u], w);
        adj[u].push_back({w, v});
    }
    for (int i = 0; i < n; i++) {
        priority_queue<myData> pq;
        pq.push({i, 0});
        while (pq.size()) {
            int u = pq.top().v;
            int w = pq.top().w;
            pq.pop();
            for (auto p: adj[u]) {
                int v = p.second;
                int d = p.first;
                if (dist[i][v] > w + d)
                {
                    dist[i][v] = w + d;
                    pq.push({v, dist[i][v]});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        // for (int j = 0; j < n; j++) cout << dist[i][j] << " ";
        cout << (dist[i][i] >= inf ? -1 : dist[i][i]);
        cout << '\n';
    }
    return 0;
}