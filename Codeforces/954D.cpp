#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
const int inf = 1e9;

int n, m, s, t;
bool a[N][N];
vector<int> adj[N];
int distS[N], distT[N];

void bfs(int x, int dist[]){
    for(int i=1; i<=n; i++) dist[i] = inf;
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while (q.size()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if (dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m >> s >> t;
    memset(a,0,sizeof a);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u][v] = a[v][u] = 1;
    }
    bfs(s, distS);
    bfs(t, distT);
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ans += (!a[i][j] && distS[i] + distT[j] + 1 >= distS[t] && distT[i] + distS[j] + 1 >= distS[t]);
        }
    }
    cout << ans;
    return 0;
}