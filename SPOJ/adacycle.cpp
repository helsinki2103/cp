#include<bits/stdc++.h>

using namespace std;
const int N = 2e3 + 5;
const int inf = 1e9;

vector<int> adj[N];
int n;
int dist[N];

int bfs(int x){
    for(int i=1; i<=n; i++) dist[i] = inf;
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    int cnt = 0;
    while (q.size()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if (v==x) return dist[u] + 1;
            if (dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return inf;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x; cin >> x;
            if (x) adj[i].push_back(j);
        }
    }
    for(int i=1; i<=n; i++){
        int cur = bfs(i);
        if (cur>=inf) cout << "NO WAY\n";
        else cout << cur << '\n';
    }
    return 0;
}