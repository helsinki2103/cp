#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

struct MST{
    int u, v, w;
    bool operator < (const MST &oth) const{
        return w<oth.w;
    }
};

struct query{
    int id, u, w;
    bool operator < (const query &oth) const{
        return w>oth.w;
    }
};

int pa[N], sz[N];

int root(int x){
    return pa[x]==-1?x:pa[x] = root(pa[x]);
}

void join(int u, int v){
    u = root(u);
    v = root(v);
    if (u==v) return;
    pa[v] = u;
    sz[u] += sz[v];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, m, q;
    while (cin >> n >> m >> q){
        for(int i=0; i<n; i++){
            pa[i] = -1;
            sz[i] = 1;
        }
        vector<MST> edge;
        vector<int> ans(q);
        for(int i=0; i<m; i++){
            int u, v, w; cin >> u >> v >> w;
            edge.push_back({u, v, w});
        }
        sort(edge.begin(),edge.end());
        vector<query> queries;
        for(int i=0; i<q; i++){
            int u, v; cin >> u >> v;
            queries.push_back({i, u, v});
        }
        sort(queries.begin(),queries.end());
        for(query qr: queries){
            while (edge.size()){
                int u = edge.back().u;
                int v = edge.back().v;
                int w = edge.back().w;
                if (w<qr.w) break;
                join(u, v);
                edge.pop_back();
            }
            ans[qr.id] = sz[root(qr.u)];
        }
        for(int i=0; i<q; i++) cout << ans[i] << '\n';
    }
    return 0;
}