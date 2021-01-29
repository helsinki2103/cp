#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

struct myData{
    int u, v, w;
    bool operator < (const myData &oth) const{
        return w>oth.w;
    }
};

int n, sz;
int p[N];
vector<int> adj[N];
int firstVertex, lastVertex;
vector<myData> comp;
bool vis[N];

void dfs(int u, int pa = -1){
    sz++;
    lastVertex = u;
    vis[u] = 1;
    for(int v: adj[u]){
        if (vis[v]) continue;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        adj[i].push_back(p[i]);
    }
    for(int i=1; i<=n; i++){
        if (!vis[i]){
            sz = 0;
            firstVertex = i;
            dfs(i);
            comp.push_back({firstVertex, lastVertex, sz});
        }
    }
    int64_t ans = 0;
    if (comp.size()<2){
        bool f = 0;
        for(int v: adj[comp[0].v]){
            if (v==comp[0].u){
                f = 1;
                break;
            }
        }
        if (f) ans = pow(comp[0].w, 2);
        else ans = 1ll * (comp[0].w + (comp[0].w) * (comp[0].w + 1) / 2);
        cout << ans;
        return 0;
    }
    sort(comp.begin(), comp.end());
    ans = pow(comp[0].w + comp[1].w, 2);
    for(int i=2; i<comp.size(); i++){
        bool f = 0;
        for(int v: adj[comp[i].v]){
            if (v==comp[i].u){
                f = 1;
                break;
            }
        }
        if (f) ans += pow(comp[i].w, 2);
        else ans += 1ll * (comp[i].w + (comp[i].w) * (comp[i].w + 1) / 2);
    }
    cout << ans;
    return 0;
}